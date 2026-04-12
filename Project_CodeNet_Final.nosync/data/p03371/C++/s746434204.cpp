#include <iostream>
using namespace std;
int main(){
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	if(A+B>C*2){
		if(X <= Y){
			if(B>C*2){
			  cout << max(X,Y)*C*2 << endl;	
			}else{
				cout << C * X * 2 + B * (Y - X) << endl;			
			}
		}else{
			if(A>C*2){
			  cout << max(X,Y)*C*2 << endl;
			}else{
				cout << C * Y * 2 + A * (X - Y) << endl;
			}
		}
		/*
		if(min(A,B)<C*2){
			if(X >= Y){
				cout << C * Y * 2 + A * (X - Y) << endl;
			}else{
				cout << C * X * 2 + B * (Y - X) << endl;
			}
		}else{
			cout << max(X,Y)*C*2 << endl;
		}*/
	}else{
		cout << A*X+B*Y << endl;
	}
	return 0;
}
