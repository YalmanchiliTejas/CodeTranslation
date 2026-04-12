#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ull;
#define base 31
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Read_ freopen("input.inp", "r", stdin)
#define Write_ freopen("output.out", "w", stdout);
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define N  200005
ull n,a[N],sum[N];
ull res;
int main(){
    _io; 
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    sum[1]=a[1];
    FOR(i,2,n) sum[i]=sum[i-1]+a[i];
    //FOR(i,1,n) cout<<sum[i]<<" ";
    res=0;
    ull mod=1000000007;
    FOR(i,1,n){
        ull x=((a[i]%mod)*((sum[n]-sum[i])%mod))%mod;
        res+=(x%(mod));
    }
    cout<<res%mod;
}


