#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
#define PP pair<int,P>
#define F first
#define S second
#define f(i,n) for(int i=0;i<(n);i++)
#define INF LLONG_MAX/3
#define eps LDBL_EPSILON
#define mod (int)(1000000007)
#define pie 3.141592653589793238462643383279
#define Bpri priority_queue
#define Spri priority_queue<P,vector<P>,greater<P>>
using namespace std;
signed main(){
	int a,b;
	string s;
	cin>>a>>s>>b;
	f(i,a){
		if(s[i]!=s[b-1]) cout<<'*';
		else cout<<s[i];
	}
	puts("");
	return 0;
}
