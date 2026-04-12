#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=998244353;

const int N=2e5+1;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    ll n,x,m;
    cin>>n>>x>>m;
    vector<ll> pref(N,0);
    map<ll,ll> mpp;
    pref[0]=x;
    mpp[x]=0;
    ll i=1, pval=x, val;
    while(i<n){
        val=(pval*pval)%m;
        if(val==0){
            cout<<pref[i-1];
            return 0;
        }
        if(mpp.find(val)!=mpp.end())
            break;
        pref[i]=pref[i-1]+val;
        mpp[val]=i++;
        pval=val;
    }
    if(i==n){
        cout<<pref[n-1];
        return 0;
    }
    ll pos=mpp[val];
    ll len=i-pos;
    ll seg=pref[i-1];
    if(pos!=0) seg-=pref[pos-1];
    n-=i;
    ll ans=pref[i-1];
    ans=ans+(n/len)*seg;
    ll rem=n%len;
    if(rem!=0){
        ans=ans+pref[pos+rem-1];
        if(pos!=0) ans-=pref[pos-1];
    }
    cout<<ans;
    //cout<<i-pos<<"\n";



    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}