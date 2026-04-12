#include <iostream>
using namespace std;

int main() {
	int A, B, C, X, Y, a=0,b=0;
	long long int sum=0;
	cin >> A >> B >> C >> X >> Y;
	if(A+B<=C*2){
		while(a<X && b<Y){
			a++; b++;
			sum += A + B;
		}
	}
	if(A+B>C*2){
		while(a<X && b<Y){
			a++; b++;
			sum += C*2;
		}
	}
	if(a<X){
		if(A<=C*2){
			while(a<X){
				a++;
				sum += A;
			}
		}
		if(A>C*2){
			while(a<X){
				a++; b++;
				sum += C*2;
			}
		}
	}
	if(b<Y){
		if(B<=C*2){
			while(b<Y){
				b++;
				sum += B;
			}
		}
		if(B>C*2){
			while(b<Y){
				a++; b++;
				sum += C*2;
			}
		}
	}
	
	cout << sum;
	return 0;
}