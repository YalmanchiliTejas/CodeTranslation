#include<bits/stdc++.h>
#include <iomanip>
#define ll long long int
#define ld long double
#define IOS cin.tie(NULL);cout.tie(NULL)
#define f first
#define inf 100000000000000000
#define ii pair<ll,ll>
#define vi vector<ll>
#define vii vector<ii>
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define sc(i) scanf("%lld",&i);
#define s second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
ll const mod=1000000007;
 
// ll arr1[10000009];
// vector<ll> sieve;
// void sievefun(ll n){
//     for(ll i=2;i<=n;i++){
//         if(arr1[i]==0){
//             for(ll j=i*i;j<=n;j+=i){
//                 arr1[j]=1;
//             }
//         }
//     }
//     for(int i=2;i<=n;i++){
//     	if(arr1[i]==0)sieve.pb(i);
//     }
// }
 
ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;
 
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}
ll power(ll x, ll y) {
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return ((temp)*(temp));
	else
		return (((x))*((temp*temp)));
}
ll gcd1(ll a, ll b){
if (a == 0)
    return b;
return gcd1(b % a, a);
}
ll lcm(ll a, ll b)
{
return (a*b)/gcd1(a, b);
}
ll dp[10009][109][2];
ll fun(string s,int d,int ind,int n,int rem,int flag){
	if(ind==n){
		if(rem==0)return 1;
		else return 0;
	}
	if(dp[ind][rem][flag]!=-1)return dp[ind][rem][flag]%mod;
	ll ans=0;
	if(flag){
		forn(i,s[ind]){
			ans+=fun(s,d,ind+1,n,(rem+i%d)%d,0);
			ans%=mod;
		}
		ans+=fun(s,d,ind+1,n,(rem+s[ind]%d)%d,1);
		ans%=mod;
	}else{
		forn(i,10){
			ans+=fun(s,d,ind+1,n,(rem+i%d)%d,0);
			ans%=mod;
		}
	}
	return dp[ind][rem][flag]=ans;
}
int main()
{	//sievefun(10000007);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	forn(i,s.length())s[i]-='0';
	ll d;
	cin>>d;
	forn(i,s.length()){
		forn(j,d){
			forn(k,2){
				dp[i][j][k]=-1;
			}
		}
	}
	fun(s,d,0,s.length(),0,1);
	cout<<(dp[0][0][1]-1+mod)%mod<<endl;
	// forn(i,s.length()){
	// 	forn(j,2){
	// 		forn(k,d){
	// 			cout<<dp[i][k][j]<<" ";
	// 		}cout<<endl;
	// 	}cout<<endl<<endl;
	// }

}