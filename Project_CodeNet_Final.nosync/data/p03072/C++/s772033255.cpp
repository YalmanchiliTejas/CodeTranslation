#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vll> vvll;
typedef pair<ll ,ll> pii;
typedef pair<string ,ll> psi;
typedef pair<ll,string > pis;
typedef pair<ll , vll> plv;

#define REP(i,a,b) for(ll i=ll(a);i<=ll(b);++i)
#define REPR(i,a,b) for(ll i=ll(a);i>=ll(b);--i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()

template <typename T> T absolute(T a,T b){ return a>=0?a:-a; }
template <typename T> T sqr(T a){return a*a;}

ll read(){
    ll res,f=1;register char ch;
    while((ch=getchar())>'9'||ch<'0')(ch=='-')&&(f=-1);
    for(res=ch-'0';(ch=getchar())>='0'&&ch<='9';res=res*10+ch-'0');
    return res*f;
}

int main(){
    ll n,cnt=0;
    scanf("%lld",&n);
    ll a[n];ll maxi=0;
    REP(i,0,n-1){
        scanf("%lld",&a[i]);
        if(a[i]>=maxi)cnt++;
        maxi=max(maxi,a[i]);
    }
    cout<<cnt<<endl;
    return 0;
}