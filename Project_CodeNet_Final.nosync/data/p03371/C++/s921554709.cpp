#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;
	int cost=0;

	if(2*C < A+B){
		if(X<Y){
			cost += 2*C*X;
			Y=Y-X;
			if(2*C < B){
				cost += 2*C*Y;
			}else{
				cost += B*Y;
			}
		}else{
			cost += 2*C*Y;
			X=X-Y;
			if(2*C < A){
				cost += 2*C*X;
			}else{
				cost += A*X;
			}
		}
	}else{
		cost += A*X+B*Y;
	}
	cout << cost << endl;
	return 0;
}
