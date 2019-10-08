#pragma once

#include <cstddef>
#include <utility>
#include <cmath>

template<typename intT>

class minimizer{
public:
    typedef intT int_type;

    typedef std::pair<intT,intT> point_type;

    template<typename comparatorT>
    std::pair<point_type, point_type> dim2_minimize(comparatorT & comp, size_t k = 8 );

    template<typename comparatorT>
    int_type dim1_minimize(comparatorT & comp, size_t k = 8);
	
	//этот метод пока не нужен
	template<typename comparatorT>
    int_type dihotomy(int_type start, int_type finish, comparatorT & comp);
};


template<typename intT> 
template<typename comparatorT>
std::pair<typename minimizer<intT>::point_type, typename minimizer<intT>::point_type>
minimizer<intT>::dim2_minimize(comparatorT & comp, size_t k)
{
	class dim1_comp {
		point_type y,z;
		comparatorT & comp;
		
		public:
		dim1_comp(const point_type & ay, const point_type & az, comparatorT & acomp)
		:y(ay),z(az), comp(acomp) {}
		
		bool operator()(const int_type & t1, const int_type & t2) const
		{
			point_type p1 = z, p2 = z;
			p1.first += t1 * y.first;
			p1.second += t1 * y.second;
			p2.first += t2 * y.first;
			p2.second += t2 * y.second;
			return comp(p1,p2);
		}
	};
	
    int_type t = 0;
    point_type y(1,0), z(0,1);

    do{
        if(!comp(y,z)) std::swap(y,z);
		auto temp = dim1_comp(y, z, comp);
		t = dim1_minimize(temp, k);
		//t = dim1_minimize(dim1_comp(y,z,comp),k);
        z.first += t * y.first;
        z.second += t * y.second;
    }while( t!= 0 );

    return std::make_pair(y,z);
}

template<typename intT>
template<typename comparatorT>
typename minimizer<intT>::int_type
minimizer<intT>::dim1_minimize(comparatorT & comp, size_t k)
{
	int_type direction = 1;
	if(comp(0,1)) direction = -1;
	
	int_type start = 0, finish = direction*k;
	while( !comp(finish - direction,finish) ) {
		start = finish;
		finish *= 2;
	}
	
	while( start != finish-direction ) {
		int_type mid = start + (finish - start)/2;
		if(comp(mid-direction,mid)) 
			finish = mid;
		else 
			start = mid;
	}
	return start;
}