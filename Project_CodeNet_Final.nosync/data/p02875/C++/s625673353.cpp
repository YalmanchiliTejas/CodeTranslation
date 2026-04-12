#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define ull unsigned long long
#define y1 asjdlfaskavslbcjasndscf
#define endl '\n'
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define iter vector< int >::iterator
#define iter1 multiset<int>::iterator
#define int long long
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<class T>
using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd1(chrono::steady_clock::now().time_since_epoch().count());

//find_by_order
//order_of_key

const int N=1e7+7;
const int inf=1e18+1e9;
const int mod=998244353;
const ld eps=1e-9;

//const int MAX_MEM=1e8;
//int mpos=0;
//char mem[MAX_MEM];
//
//inline void * operator new(size_t n){
//    char *res=mem+mpos;
//    mpos+=n;
//    assert(mpos<=MAX_MEM);
//    return (void*)res;
//}
//
//inline void operator delete(void *) {}

int f[N],st2[N];
int rev[N];

int st(int n,int k)
{
    int res=1;
    while(k){
        if (k%2==1){
            res=(res*n)%mod;
        }
        n=(n*n)%mod;
        k/=2;
    }
    return res;
}

int C(int n,int k)
{
    int ans=f[n];
    ans=(ans*rev[k])%mod;
    ans=(ans*rev[n-k])%mod;
    return ans;
}

main ()
{
    ios;
    st2[0]=1;
    for (int i=1;i<N;++i){
        st2[i]=(st2[i-1]*2)%mod;
    }
    f[0]=1;
    for (int i=1;i<N;++i){
        f[i]=(f[i-1]*i)%mod;
    }
    rev[N-1]=st(f[N-1],mod-2);
    for (int i=N-2;i>=0;--i){
        rev[i]=(rev[i+1]*(i+1))%mod;
    }
    int n;
    cin>>n;
    int ans=st(3,n);
    int f=0;
    for (int i=n/2+1;i<=n;++i){
        f+=(C(n,i)*st2[n-i])%mod;
        f%=mod;
    }
    f=(f*2)%mod;
    ans=(ans-f+mod)%mod;
    cout<<ans<<endl;
}
