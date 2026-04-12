#include<bits/stdc++.h>
using namespace std;

int main(void){
	int A,B,C,X,Y;
	int ans = 0;
	cin >> A>>B>>C>>X>>Y;
	if(C*2<A+B){
		ans += min(X,Y)*C*2;
		if(X>Y)ans+=A*(X-Y);
		else ans+=B*(Y-X);
	}
	else ans = A*X+B*Y;
	if((X-Y>0&&A>C*2)||(Y-X>0&&B>C*2))ans = min(max(X,Y)*C*2,ans);
	cout << ans <<endl;
	
	return 0;
}