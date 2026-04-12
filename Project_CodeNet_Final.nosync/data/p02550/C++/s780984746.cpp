#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 100005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint n,x,m;
    cin>>n>>x>>m;
    vector<lint> vis(m,0);
    vector<lint> pr(100005,0),ps(100005,0);
    vis[x]=1;
    lint pos=2,sm=x;pr[1]=x;ps[x]=1;
    while(pos<=n){
        x=(x*x)%m;
        if(!x){
            cout<<sm;
            return 0;
        }
        if(vis[x]) break;
        vis[x]=1;
        ps[x]=pos;
       // cout<<x<<' '<<ps[x]<<endl;
        sm=sm+x;
        pr[pos]=sm;
        pos++;
    }
    if(pos>n) cout<<sm;
    else{
        pos--;n-=pos;

        lint pss=ps[x]-1,ds=sm-pr[pss],dl=pos-pss;
       // cout<<pos<<' '<<n<<' '<<pss<<' '<<ds<<' '<<dl<<endl;
        sm=sm+ds*(n/dl)+pr[pss+n%dl]-pr[pss];
        cout<<sm;
    }
    return 0;
}
