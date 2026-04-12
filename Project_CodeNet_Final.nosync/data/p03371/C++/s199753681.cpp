#include<iostream>
#include<string>

using namespace std;

int main(void){
	long A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	if(A + B < C*2){
		cout << A*X + B*Y << endl;
	}else{
		long min;
		long money = 0;
		long rest = 0;
		// 最小の数数だけABピザを買う
		if(X > Y){
			min = Y;
			if(A > C*2){
				rest = C * (X-Y)*2;
			}else{
				rest = A * (X-Y);
			}
		}else{
			min = X;
			if(B > C*2){
				rest = C * (Y-X)*2;
			}else{
				rest = B * (Y-X);
			}
		}
		money += min * C*2;
		cout << money + rest << endl;
	}
	return 0;
}