//#include<i_am_noob_orz>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ull unsigned long long
#define pii pair<int,int>
#define X first
#define Y second
#define mod ((ll)1e9+7)
#define pb push_back
#define mp make_pair
#define abs(x) ((x)>0?(x):(-(x)))
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
#define memres(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define endl '\n'
#define bit_count(x) __builtin_popcount((x))
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define LOCAL
#ifdef LOCAL
#define debug(a) cerr<<#a<<" "<<a<<endl;
#else
#define debug(a)
#endif
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	if(n>=30)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
return 0;
}
