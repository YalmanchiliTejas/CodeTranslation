#include<bits/stdc++.h>
using namespace std;
int main(){
	long long A,B,C,X,Y,ans1,ans2,ans3,i=0;
	cin>>A>>B>>C>>X>>Y;
	ans1=A*X+B*Y;
	ans2=C*max(X,Y)*2;
	if(X>Y){i=(X-Y)*A;}
	if(Y>X){i=(Y-X)*B;}
	ans3=C*min(X,Y)*2+i;
	ans1=min(ans1,ans2);
	cout<<min(ans1,ans3);
	return 0;
}