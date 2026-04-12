#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
	int A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y;
	int res=0;
	if(A+B>2*C){
		if(X>Y){
			res+=Y*2*C;
			if(A>2*C){
				res+=(X-Y)*2*C;
			}else{
				res+=(X-Y)*A;
			}
		}else{
			res+=X*2*C;
			if(B>2*C){
				res+=(Y-X)*2*C;
			}else{
				res+=(Y-X)*B;
			}
		}
	}else{
		res+=A*X+B*Y;
	}
	cout<<res;
	return 0;
} 