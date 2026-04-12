#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

signed main(){
	int r=read(),g=read(),b=read();
	
	int num = 100*r+10*g+b;
	
	if(num%4==0) cout << "YES";
	else	cout << "NO";
}