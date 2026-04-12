#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define dd double
#define oo 1001007000
#define ff float
#define ooo 4223352036854775007
#define iii pair<ll,ll>
#define vii vector<ll>
#define viii vector<iii>
#define sss pair<str,str>
#define str string
#define sii set<ll>
#define siii set<iii>
#define r0 return 0
#define pb push_back
#define sz size
using namespace std;

const char E='\n';
const int N=400005;
const int NN=20005;
const ll md=998244353;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n,x,m;
    cin >> n >> x >> m;
    ll a[N]={0};
    a[1]=x;
    map<ll,int> pos;
    pos[x]=1;
    int l=-1,r=-1;
    for (int i=2;i<=n;i++){
        x*=x;
        x%=m;
        if (pos[x]!=0){
            r=i-1;
            l=pos[x];
            break;
        }else {
            a[i]=x;
            pos[x]=i;
        }
    }
    if (l==-1){
        ll ans=0;
        for (int i=1;i<=n;i++){
            ans+=a[i];
        }
        cout << ans << E;
        r0;
    }
    ll sum=0;
    for (int i=l;i<=r;i++){
        sum+=a[i];
    }
    int len=r-l+1;
    ll ans=0;
    for (int i=1;i<=r;i++){
        ans+=a[i];
    }
    ans+=((n-r)/len)*sum;
    for (int i=l;i<=((n-r)%len)+l-1;i++){
        ans+=a[i];
    }
    cout << ans << E;
    r0;
}
/*








*/
