#include <bits/stdc++.h>
using namespace std;

#define mainspring cout<<"mainspring\n";
#define barrel cout<<"barrel\n";
#define escapement cout<<"escapement\n";
#define int long long

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define fs first
#define sd second
#define tik(i,a,b) for(int i = a; i < b; i++)
#define tok(i,a,b) for(int i = a; i >= b; i--)
#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it,args);}

typedef long long ll;
typedef unsigned long long ull;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void err(istream_iterator<string> it) {cout << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " ";
    err(++it, args...);
}
int ways[3005][3005];
int a[3005];
int32_t main() {
	int n,s; cin>>n>>s;
	for(int i=1;i<=n;i++) cin>>a[i];

	int ans=0,mod=998244353;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s;j++) ways[i][j]=ways[i-1][j];

		if(a[i]>s) continue;
		ways[i][0]=i;
		int val=ways[i][s-a[i]]*(n-(i-1));
		// cout<<i<<" "<<ways[i][s-a[i]]<<endl;
		ans=(ans+val)%mod;

		ways[i][a[i]]=(ways[i][a[i]]+i)%mod;
		for(int j=1;j<=s-a[i];j++){
			ways[i][j+a[i]]=(ways[i][j+a[i]]+ways[i-1][j])%mod;
		}
		// ways[i]
		// for(int i=)
	}
	cout<<ans;

}