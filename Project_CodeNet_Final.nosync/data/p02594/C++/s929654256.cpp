/*
                                        //     //     //\\\\\\\\\
                                        \\    //      \\        \\
                                        //   //       //         \\
                                        \\  //        \\          \\
                                        // //         //           \\
                                        \\//          \\            \\       
                                        //\\          //            //
                                        \\ \\         \\           //
                                        //  \\        //          //
                                        \\   \\       \\         //
                                        //    \\      //        //
                                        \\     \\     \\/////////
*/

#include <bits/stdc++.h>
//#include <boost/math/common_factor.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
#define ff first
#define ss second
#define endl cout<<'\n'
#define fre(i,l,n) for(long long int i=l;i<n;++i)
#define fr(i,l,n) for(long long int i=l;i<=n;i++)
#define rfre(i,n,l) for(long long int i=n-1;i>=l;i--)
#define rfr(i,n,l) for(long long int i=n;i>=l;--i)
#define tab '\t'
#define debug cout<<'*';
#define s(a) cin>>a
#define p(a) cout<<a
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef pair<int,pair<int,int> > ppii;
typedef vector<int> vec;
typedef vector<long long> vecll;
typedef vector<pair<int,int> > vec_pii;
typedef vector<pair<long long int,long long int> > vec_pll;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pair<int,int> > > vvpii;
typedef vector<vector<pair<ll,ll> > > vvpll;
typedef priority_queue<pll, vec_pll, greater<pll> > minpqpll;
typedef priority_queue<pll> maxpqpll;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define Pi 3.14159265358979
#define gcd(a,b) __gcd(a,b)
#define sf(n) scanf("%lld",&(n))
#define pf(n) printf("%lld\n",(n))
#define min3(a,b,c) (min((c),min((a),(b))))
#define max3(a,b,c) (max((a),max((b),(c))))
#define w(t) while(t--)
#define flt(a) cout<<fixed<<setprecision(a)
#define cntSetBits(n) __builtin_popcountll(n)
#define INF 1e18+100
/*****************************
*****************************/


// const ll MAXN = 1000000;
// ll spf[MAXN+5];
// ll prime[MAXN+5];
// ll fact[MAXN+5];
// ll invfact[MAXN+5];
// ll arr[MAXN+5];


// void sieve()
// {
// 	fr(i,1,MAXN)
// 	{
// 		spf[i] = i;
// 	}
// 	for(ll i=2;i<=MAXN;i++)
// 	{
// 		if(spf[i] == i)
// 		{
// 			for(ll j=i*i;j<=MAXN;j+=i)
// 			{
// 				if(spf[j] == j)
// 				{
// 					spf[j] = i;
// 				}
// 			}
// 		}
// 	}
// }


// ll power(ll a, ll b, ll modi)
// {
//     ll res = 1;
//     while(b)
//     {
//         if(b & 1)
//         {
//             res = (res%modi * a%modi)%modi;
//         }
//         a = (a%modi * a%modi)%modi;
//         b >>= 1;
//     }
//     return res;
// }


// void facto()
// {
//     fact[0] = 1;
//     fr(i,1,MAXN)
//     {
//         fact[i] = (fact[i-1]%mod * i%mod)%mod;
//     }
//     invfact[MAXN] = power(fact[MAXN],mod-2);
//     rfre(i,MAXN,0)
//     {
//         invfact[i] = (invfact[i+1]%mod * (i+1)%mod)%mod;
//     }
// }



// ll nCr(ll n,ll r)
// {
//     return (fact[n]%mod * invfact[r]%mod * invfact[n-r]%mod)%mod;
// }






// void initialise()
// {
//     memset(vis,0,sizeof(vis));
//     fre(i,0,MAXN)
//     {
//         adj[i].clear();
//     }
// }


// bool isvowel(char ch)
// {
//     if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//     {
//         return true;
//     }
//     return false;
// }










void solve()
{
    // initialise();
   	ll x;
   	s(x);
   	x >= 30 ? p("Yes") : p("No");endl;
}



int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // facto();
    // sieve();
    ll t=1;
    // s(t);
    w(t)
    {
        solve();
    }
    return 0;
}






