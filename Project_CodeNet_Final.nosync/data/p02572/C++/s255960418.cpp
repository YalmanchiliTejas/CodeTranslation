//noob
#include<bits/stdc++.h>
using namespace std;
#define fori(x) for(int i=0;i<x;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long int 
#define ld long double
#define ull unsigned long long int
#define pi acos(-1)
#define test() int T,t=1;cin>>T;
#define all(x) (x).begin(),(x).end()
typedef vector<int> vi;
typedef pair<int,int> PI;
const int MOD = (int)1e9 + 7;

void solve()
{	
   int n;cin>>n;
   ll a[200000];
   fori(n) cin>>a[i];
   vector<ll>sum;
   ll temp=0;
   for(int i=0;i<n;i++){
   	temp+=a[i];
   	sum.pb(temp%MOD);
   }
   ll ans=0;
   for(int i=1;i<n;i++){
   	int x=i-1;
   	ans+=(a[i]*sum[x])%MOD;
   }
   cout<<ans%MOD<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//freopen("input.txt","r",stdin);
	
solve();
	return 0;
}