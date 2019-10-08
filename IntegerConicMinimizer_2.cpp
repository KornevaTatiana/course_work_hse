// IntegerConicMinimizer.cpp: определяет точку входа для приложения.
//

#include "IntegerConicMinimizer.h"
#include <fstream>
#include <math.h>
#include <ctime>

using namespace std;
typedef long long int_type;
typedef minimizer<int_type> minimizer_type;
typedef typename minimizer<int_type>::point_type point_type;

int main()
{
	srand((unsigned)time(NULL));
    // gsd_64
   /* ofstream file_gcd64;
	file_gcd64.open("gcd64_big_big_big_big_big_R.txt");
	minimizer_type my_minimizer;
	int_type a, b, c;
	
    for(int i=0; i<100000; i++)
    {        
		a = (int_type)(rand() % 9) +
			10 * (int_type)(rand() % 9) +
			100 * (int_type)(rand() % 9) +
			1000 * (int_type)(rand() % 9) +
			10000 * (int_type)(rand() % 9) +
			100000 * (int_type)(rand() % 9) +
			1000000 * (int_type)(rand() % 9) +
			10000000 * (int_type)(rand() % 9) +
			100000000 * (int_type)(rand() % 9) +
			1000000000 * (int_type)(rand() % 9) +
			10000000000 * (int_type)(rand() % 9) +
			100000000000 * (int_type)(rand() % 9) +
			1000000000000 * (int_type)(rand() % 9) +
			10000000000000 * (int_type)(rand() % 9) +
			100000000000000 * (int_type)(rand() % 9) +
			1000000000000000 * (int_type)(rand() % 9) +
			10000000000000000 * (int_type)(rand() % 9) +
			100000000000000000 * (int_type)(rand() % 9) +
			1000000000000000000 * (int_type)(rand() % 9) +			
			10000000000000000000 * ((int_type)(rand() % 9) + 1);		    
		b = (int_type)(rand() % 9) +
			10 * (int_type)(rand() % 9) +
			100 * (int_type)(rand() % 9) +
			1000 * (int_type)(rand() % 9) +
			10000 * (int_type)(rand() % 9) +
			100000 * (int_type)(rand() % 9) +
			1000000 * (int_type)(rand() % 9) +
			10000000 * (int_type)(rand() % 9) +
			100000000 * (int_type)(rand() % 9) +
			1000000000 * (int_type)(rand() % 9) +
			10000000000 * (int_type)(rand() % 9) +
			100000000000 * (int_type)(rand() % 9) +
			1000000000000 * (int_type)(rand() % 9) +
			10000000000000 * (int_type)(rand() % 9) +
			100000000000000 * (int_type)(rand() % 9) +
			1000000000000000 * (int_type)(rand() % 9) +
			10000000000000000 * (int_type)(rand() % 9) +
			100000000000000000 * (int_type)(rand() % 9) +
			1000000000000000000 * (int_type)(rand() % 9) +
			10000000000000000000 * ((int_type)(rand() % 9) + 1);		   	   
        cout << i << " " << a << "    " << b << endl;
        gcd_oracle<int_type> gcd64(a,b);
        auto result_gcd = my_minimizer.dim2_minimize(gcd64);
        file_gcd64 << i << ";" << a << ";" << b << ";" << result_gcd.first.first << ";" << result_gcd.first.second << ";";
        file_gcd64 << result_gcd.second.first << ";" << result_gcd.second.second << ";";
        file_gcd64 << gcd64.evaluate(result_gcd.first) << ";" << gcd64.evaluate(result_gcd.second) << ";";
        file_gcd64 << gcd64.get_count() << endl;
    }
    file_gcd64.close();*/
	

    // quad	
    ofstream file_quad;
    file_quad.open("quad_big_R_1.txt");	
	minimizer_type my_minimizer;
	int_type a, b, c, temp;
    for(int_type i=0; i<100000; i++)
    {		
		a = (int_type)(rand() % 9) + 1;					
		b = (int_type)(rand() % 9) +
			10 * (int_type)(rand() % 9) +
			100 * (int_type)(rand() % 9) +					
			1000 * (int_type)(rand() % 9)+
			10000 * (int_type)(rand() % 9)+
			100000 * (int_type)(rand() % 9)+
			1000000 * (int_type)(rand() % 9)+			
			10000000 * (int_type)(rand() % 9)+			
			100000000 * (int_type)(rand() % 9);
        if (rand() % 2 == 0) {b = 0-b;}
        temp = ceil(b*b/a);
        c = (int_type)rand() + temp;
		if (c == 0) {c++; }
		//
		//a = //(int_type)(rand() % 9) +
		//	//10 * (int_type)(rand() % 9) +
		//	//100 * (int_type)(rand() % 9) +
		//	//1000 * (int_type)(rand() % 9) +	
		//	//10000 * (int_type)(rand() % 9) +
		//	//100000 * (int_type)(rand() % 9) +
		//	100 * ((int_type)(rand() % 9) + 1);
		//b = (int_type)(rand() % 9) +
		//	10 * (int_type)(rand() % 9) +
		//	//100 * (int_type)(rand() % 9) +
		//	//1000 * (int_type)(rand() % 9) +		
		//	//10000 * (int_type)(rand() % 9) +
		//	//100000 * (int_type)(rand() % 9) +
		//	100 * ((int_type)(rand() % 9) + 1);
		//if (rand() % 2 == 0) { b = 0 - b; }
		//int_type temp = ceil((b*b)/a);
		//c = -1;
		//while(true)
		//{
		//	c = (int_type)(rand() % 9) + 1;
		//	//10 * (int_type)(rand() % 9) +
		//	//100 * (int_type)(rand() % 9) +
		//	//1000 * (int_type)(rand() % 9) +		
		//	//10000 * (int_type)(rand() % 9) +
		//	//100000 * (int_type)(rand() % 9) +
		//	//1000 * ((int_type)(rand() % 9) + 1);
		//	c = c + temp;
		//	if (c == 0) { c++; }
		//	if (c > ceil((b * b) / a)) 
		//	{ break; }
		//}
				
        cout <<  i << "    " << a << "    " << b << "    " << c << endl;
        positive_definite_oracle<int_type> quad(a,b,c);		
        auto result_quad = my_minimizer.dim2_minimize(quad);		
        file_quad << i << ";" << a << ";" << b << ";" << c << ";";
        file_quad << result_quad.first.first << ";" << result_quad.first.second << ";";
        file_quad << result_quad.second.first << ";" << result_quad.second.second << ";";
        file_quad << quad.evaluate(result_quad.first) << ";" << quad.evaluate(result_quad.second) << ";";
        file_quad << quad.get_count() << endl;
    }
    file_quad.close();
	return 0;
}
	

//    minimizer_type my_minimizer;
//    gcd_oracle<int_type> gcd64(6,4);
//    positive_definite_oracle<int_type> quad(11, -100, -200);
//    auto result_gcd = my_minimizer.dim2_minimize(gcd64);
//    auto result_quad = my_minimizer.dim2_minimize(quad);
//
//    cout << "The first and second minimum points are: (" << result_gcd.first.first << ", " << result_gcd.first.second << "), ("
//         << result_gcd.second.first << ", " << result_gcd.second.second << ")." << endl;
//    cout << "The first and second minimum are: " << gcd64.evaluate(result_gcd.first) << ", " << gcd64.evaluate(result_gcd.second) << endl;
//    cout << "Number of calls to the oracle is: " << gcd64.get_count() << endl;
//
//    cout << "The first and second minimum points are: (" << result_quad.first.first << ", " << result_quad.first.second << "), ("
//         << result_quad.second.first << ", " << result_quad.second.second << ")." << endl;
//    cout << "The first and second minimum are: " << quad.evaluate(result_quad.first) << ", " << quad.evaluate(result_quad.second) << endl;
//    cout << "Number of calls to the oracle is: " << quad.get_count() << endl;
//    cin.ignore();

