//Optional FAST
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
 
//Required Libraries
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
//Required namespaces
 
using namespace std;
using namespace __gnu_pbds;
//typedef
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long,long> pll;

//define
#define inp(X) cin>>X;
#define inp_long(X) long long X; cin>>X;
#define inp_arr(A,N) long long A[N]; for(long long int i=0;i<N;i++) {cin>>A[i];}
#define sz(A) A.size()
#define pb push_back
#define pf push_front
#define fi first
#define se second
//#define endl '\n'
#define vect(A) vector<long long> A;
#define inp_vect(A,N); vect(A);for(long long i=0;i<N;i++){long long q; cin>>q; A.push_back(q);}
#define forin(i,a,b) for(long long i=a;i<=b;i++)
#define forde(i,a,b) for(long long i=a;i>=b;i--)
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const long long inf=(long long)1e18;
const long long MOD=(long long)(1e9+7);

ll power(ll x,ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2) % MOD;
    p = (p * p) % MOD;

    return (y%2 == 0)? p : (x * p) % MOD;
}
ll modInverse(ll a)
{
   return power(a,MOD-2);
}
ll z[1001][11]={0};
int main()
{
   /*#ifndef ONLINE_JUDGE
       freopen ("input.txt" , "r" , stdin);
		// freopen ("OUTPUT.txt" , "w" , stdout);
	#endif 
    */
    fio;
    ll n,m;
    cin>>n>>m;
    if(m==n)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    cout<<endl;
}