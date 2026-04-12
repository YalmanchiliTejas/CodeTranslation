#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for(int i = n; i >= 0; ++i)
#define FDS(i, n) for(int i = 0; i < n; ++i)
#define FDSR(i, n) for(int i = n; i >= 0; ++i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define FORR(i, m, n) for(int i = m;i >= n;--i)
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define itn int
#define ednl endl
using namespace std;
typedef long long ll;
int main(){
	ll A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y;
	if(X==Y){
		cout<<min((C*2*X),((A+B)*X))<<endl;
	}
	else{
	    ll sum=0;
		int t=min(X,Y);
		sum+=(min({(C*2),(A+B)}))*t;
		if(X>Y){
			sum+=min({(C*2),A})*(X-t);
		}
		else{
			sum+=min(C*2,B)*(Y-t);
		}
		cout<<sum<<endl;
	}
}