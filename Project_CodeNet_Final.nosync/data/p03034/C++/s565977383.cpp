#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gpu_hash_map<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 100001;
int arr[mxN];
ll sumx[mxN];
int rsum[mxN];
ll sumxmod[mxN];
int lsummod[mxN];
int n;
vector<int> divs[mxN];
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    owo(i, 0, n) {
        cin>>arr[i];
    }
    owo(i, 1, n) {
        for(int j=i; j<n; j+=i) {
            divs[j].senpai(i);
        }
    }
    owo(i, 1, n) {
        for(int j=0; j<n; j+=i) {
            sumx[i]+=arr[j];
            rsum[i] = j;
        }
        int rem = n-1;
        while(rem-i>0) {
            rem-=i;
        }
        for(int j=rem; j<n; j+=i) {
            sumxmod[i]+=arr[j];
        }
        lsummod[i] = rem;
        //cout<<i<<" "<<sumx[i]<<" "<<sumxmod[i]<<"\n";
    }
    ll ans = 0;
    owo(A, 1, n) {
        int pos = n-1-A;
        for(int k: divs[pos]) {
            if(k>=A)continue;
            if(A%k==0) {
                if(pos>=A)continue;
                while(lsummod[k]<A) {
                    sumxmod[k]-=arr[lsummod[k]];
                    lsummod[k]+=k;
                }
                while(rsum[k]>pos) {
                    sumx[k]-=arr[rsum[k]];
                    rsum[k]-=k;
                }
                //cout<<A<<" "<<pos<<" "<<k<<" "<<rsum[k]<<" "<<lsummod[k]<<"\n";
                ans = max(ans, sumx[k] + sumxmod[k]);
            }else {
                int lastpos = pos+A-k;
                while(lsummod[k]<A) {
                    sumxmod[k]-=arr[lsummod[k]];
                    lsummod[k]+=k;
                }
                while(rsum[k]>pos) {
                    sumx[k]-=arr[rsum[k]];
                    rsum[k]-=k;
                }
                ans = max(ans, sumx[k] + sumxmod[k]);
            }
            //cout<<A<<" "<<pos<<" "<<k<<" "<<ans<<"\n";
        }
    }
    cout<<ans<<"\n";
    return 0;
}