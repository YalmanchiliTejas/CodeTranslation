#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int A, B, C, X, Y;
	int res = 0;
	cin >> A >> B >> C >> X >> Y;
	if((A+B)>=C*2){
		if(X>=Y){
			if(A>=C*2){
				res = C*2*X;
			}else{
		 		res = C*2*Y + A*(X-Y);
			}
		}else if(B>=C*2){
				res = C*2*Y;
			}else{
				res = C*2*X + B*(Y-X);
		}
	}else{
		res = A*X+B*Y;
	}
	cout << res << endl;
	return 0;

}