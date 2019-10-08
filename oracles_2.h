#pragma once

#include <utility>
#include <cmath>

// НОД
template<typename intT>

class gcd_oracle {
public:
	typedef intT int_type;
	typedef std::pair<int_type, int_type> point_type;

private:
	int_type a, b;
	size_t counter;

public:

	gcd_oracle(const int_type& aa, const int_type& ab, size_t acounter = 0) :a(aa), b(ab), counter(acounter){}

	int_type evaluate(const point_type& p) const {
		return std::abs(a * p.first + b * p.second);
	}

	bool operator()(const point_type & p1, const point_type & p2) {
		++counter;
		return evaluate(p1) <= evaluate(p2);
	}

	size_t get_count() const { return counter; }
};


// Положительно определённая квадратная форма
template<typename intT>
class positive_definite_oracle {
public:
	typedef intT int_type;
	typedef std::pair<int_type, int_type> point_type;

private:
	int_type a, b, c;
	size_t counter;

public:

	positive_definite_oracle(const int_type& aa, const int_type& ab, const int_type& ac, size_t acounter = 0)
		:a(aa), b(ab), c(ac), counter(acounter){}

	int_type evaluate(const point_type & p) const {
		const int_type & x = p.first;
		const int_type & y = p.second;
		return a*x*x + c*y*y + 2*b*x*y;
	}

	bool operator()(const point_type & p1, const point_type & p2) {
		++counter;
		return evaluate(p1) <= evaluate(p2);
	}

	size_t get_count() const { return counter; }
};