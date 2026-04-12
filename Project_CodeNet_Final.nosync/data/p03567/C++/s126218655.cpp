#include<bits/stdc++.h>
#define de(x) cout<<#x<<"="<<x<<endl;
#define dd(x) cout<<#x<<"="<<x<<" ";
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define repd(i,a,b) for(int i=a;i>=(b);--i)
#define ll long long
#define mt(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define pdd pair<double,double>
#define pdi pair<double,int>
#define mp(u,v) make_pair(u,v)
#define sz(a) a.size()
#define ull unsigned long long
#define ll long long
#define pb push_back
#define PI acos(-1.0)
const int mod = 1e9+7;
const int maxn = 1e5+5;
const double EPS = 1e-6;
using namespace std;
int main()
{
	string s;
	cin>>s;
	int fg=0;
	rep(i,0,sz(s)-1){
		if(s[i]=='A'&&s[i+1]=='C') fg=1;
	}
	puts(fg?"Yes":"No");
	return 0;
}

