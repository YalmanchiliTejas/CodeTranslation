#include<iostream>

using namespace std;

int summorize(int rest,int AB,int smaller,int bigger_value)
{
   return 2 * AB * smaller + rest * bigger_value;
   
}

int summorize(int AB,int bigger)
{

	return 2 * AB * bigger;
	
}


int main(void){
	
	int A,B,AB;
	
	int X,Y;
	
	int sum1 = 0;
	int sum2 = 0;
	int rest;
	
	int c;
	
	cin >> A >> B >> AB >> X >> Y;
	
	if(2 * AB < A + B){
		
		if( X < Y){
			
			rest = Y - X;
			
			sum1  = summorize(rest,AB,X,B);
			sum2 = summorize(AB,Y);
			
			c = sum1 < sum2 ? sum1 : sum2;
			
			cout << c;
			
		}else{
					
			
			rest = X - Y;
			
			sum1 = summorize(rest,AB,Y,A);
			sum2 = summorize(AB,X);
			
			c = sum1 < sum2 ? sum1 : sum2;
			
			cout << c;
			
		}
		
	}else{
		
		
		cout << X * A + Y * B;
		
	}
	
	return 0;
	
}