#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test int t;cin>>t;while(t--)
#define REP(i,n) for (int i = 1; i <= n; i++)
#define MOD 1000000007
#define ll long long
#define ld long double
#define int ll
#define pb push_back
#define ii pair<int,int>
#define llll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define vllll vector<llll>
#define ff first
#define ss second
#define INF 1000000000
#define HINF 1000000000000000
#define mem(a,b) memset(a,b,sizeof(a))
#define arrin(x,n) int x[n]; for(int o=0;o<n;o++) cin>>x[o]
#define arrout(x,n) for(int o=0;o<n;o++) cout<<x[o]<<" "; cout<<endl
#define all(x) x.begin(),x.end()
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<" "<<#y<<'='<<y<<endl
#define deb3(x,y,z) cout<<#x<<'='<<x<<" "<<#y<<'='<<y<<" "<<#z<<'='<<z<<endl
#define debarr(arr,n) for(int o=0;o<n;o++) deb2(o,arr[o])
#define IO freopen("input.txt", "r", stdin); freopen("output.txt", "w+", stdout)
const double pi = 3.14159265358979323846;

ll power(ll a, ll b){//a^b
    ll res=1;
    //a=a%MOD;
    while(b>0){
        if(b&1)
		{res=(res*a);
		//res%=MOD;
		b--;}
        a=(a*a);
        //a%=MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
int C(int n,int k)
{
	int ans=1;
	if(k>n-k)
	k=n-k;
	for(int i=1;i<=k;i++)
	ans*=(n-i+1),ans/=i;
	return ans;
}

void solve()
{

	int i=0,j=0,k=0,m,n,p,sum=0,cnt=0;
	cin>>n;
	if(n>=30)
	cout<<"Yes";
	else cout<<"No";
	
}
int32_t main() {
    fast
    //IO;
	//cout<<fixed<<setprecision(6);
    //test
    {
        
        solve();
		
		      
    }
    return 0;
}
  