#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,y;
	cin>>n;
	
	y=n/15;
	n*=800;
	y*=200;

	cout<<n-y<<endl;
return 0;
}