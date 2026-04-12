#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define INF 10000000000

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
	int A,B,C,D,X,Y;
	cin>>A>>B>>C>>X>>Y;
	if(X>Y)D=A;
	else D=B;
	int ans=0;
	ans+=min(min(X,Y)*A+min(X,Y)*B,2*C*min(X,Y));
	ans+=min(2*C*(max(X,Y)-min(X,Y)),(max(X,Y)-min(X,Y))*D);
	
	cout<<ans<<endl;
	
	return 0;
}