#include<bits/stdc++.h>				//Written by ThiDaiLoc
using namespace std;				//Team Three Wolves
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> triple;
#define fu(i,a,b)   for(ll i=a;i<=b;i++)
#define fd(i,b,a)   for(ll i=b;i>=a;i--)
#define ms(a,x)     memset(a, x, sizeof a)
#define prec(n)     fixed<<setprecision(n)
#define uni(a)      (a).erase(unique(all(a)), (a).end())
#define pb(i)       push_back(i)
#define popb()      pop_back()
#define sc(a)       cin>>a
#define sc2(a,b)    cin>>a>>b
#define pr(a)       cout<<a<<" "
#define pr2(a,b)    cout<<a<<" "<<b<<" "
#define lowb(a,n,x) lower_bound(a,a+n,x) -a
#define lowb2(a,x)  lower_bound(all(a),x) -a.begin()
#define all(x)      (x).begin(), (x).end()
#define sz(a)       (ll)a.size()
#define le(s)       (ll)s.length()						
#define re          return 	
#define	mp(a,b)     make_pair(a,b)
#define se          second
#define fi          first 
#define debug(x)    cerr << #x << " = " << x << endl
#define INPUT       freopen("locin.txt", "r", stdin)
#define OUTPUT      freopen("locout.txt", "w", stdout)
void inline minize(ll& a,ll b){a=(a>b?b:a);};
void inline maxize(ll& a,ll b){a=(a<b?b:a);};
string inline toString(ll n) {stringstream ss; ss << n;return ss.str();}
double const eps = 1e-6;
ll const Base=1e9+7,oo=1e17,MAXN=1e6;


ll add[MAXN+5];
triple arr[MAXN+5];
bool cmp_se(triple a,triple b){
	re a.se.fi<b.se.fi;
}
ll Solves(){
	
	ll n,m,k,cnt=0,ans=0,x,a,b,prevcnt,cnt2=0;
	// PROCESSING IN HERE
	sc(n);
	fu(i,0,n-1)sc(arr[i].fi),arr[i].se.fi=arr[i].fi;
	
	sort(arr,arr+n,cmp_se);
	while(arr[n-1].se.fi>=n){
		cnt2=0;
		fd(i,n-1,0){
			arr[i].se.se+=(arr[i].se.fi+cnt2)/n;
			cnt2+=(arr[i].se.fi+cnt2)/n;
		}
		cnt+=cnt2;
		fu(i,0,n-1)arr[i].se.fi=arr[i].fi-arr[i].se.se*n+cnt-arr[i].se.se;
		sort(arr,arr+n,cmp_se);
	}
	
	pr(cnt);
	re 0;
	// Hack it if you can :)
}

int main(){
//	INPUT;
	ll JUDGE_ONLINE = 1;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solves();
	if (!JUDGE_ONLINE) cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";  
		
}