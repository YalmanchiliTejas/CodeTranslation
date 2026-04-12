#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define MAX 2020
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 7;



ll recurs(string& k, ll ind, ll need, ll d, vector<vector<ll> >& dp){
	ll len = (ll)k.length() - 1 - ind;
	if(len < (ll)0)
		return (need == 0);
	ll sum = 0;
	for(ll i = 0; i<(k[ind]-'0'); i++){
		sum+=dp[len][((need-i)%d + d)%d];
//		cout<<"we added "<<dp[len][((need-i)%d + d)%d]<<endl;
		sum%=modulo;
	}
//	cout<<"sum for now at "<<ind<<" "<<sum<<endl;
	need = ((need-(k[ind]-'0') )%d + d)%d;
	sum+=recurs(k, ind+1, need, d, dp);
	sum%=modulo;
	return sum;
}

void deal(){
	string k;
	ll d;
	cin>>k>>d;
	ll n = k.length() + 3;
	vector<vector<ll> > dp(n,vector<ll>(d,0) );
	dp[0][0] = 1;
	for(ll i = 1;i<n; i++){
		for(ll j =1; j<10; j++){
			fork(d){
				ll ind = (k+j)%d;
				dp[i][ind]+=dp[i-1][k];
				dp[i][ind]%=modulo;
			}
		}
		fork(d)
			dp[i][k]+=dp[i-1][k], dp[i][k]%=modulo;
	}
//	cout<<"we here "<<endl;
	cout<<(recurs(k, 0, 0, d, dp)+modulo-1)%modulo<<endl;
	
//	cout<<"yay "<<endl;
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
} 







