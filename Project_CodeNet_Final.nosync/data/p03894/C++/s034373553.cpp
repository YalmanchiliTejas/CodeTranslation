#include <bits/stdc++.h>
#define pb push_back

using namespace std;

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

typedef pair<int,int> pii;
typedef long long int ll;
typedef long double ld;

const int DMAX = 1e5+10;

vector <int> vec;
vector <int> arb[DMAX];

bool V[DMAX];
bool uz[DMAX];

int n,q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t,i,j;
    int x,y;

    cin>>n>>q;
    V[1]=true;
    uz[2]=true;
    for(i=1;i<=q;i++){
        cin>>x>>y;
        swap(uz[x],uz[y]);
        swap(V[x],V[y]);
        if(V[x])
            uz[x-1]=uz[x+1]=1;
        if(V[x-1] || V[x+1])
            uz[x]=1;
        if(V[y])
            uz[y-1]=uz[y+1]=1;
        if(V[y-1] || V[y+1])
            uz[y]=1;
    }
    int ans=0;
    for(i=1;i<=n;i++)
        ans+=(uz[i] || V[i]);
    cout<<ans<<'\n';

    return 0;
}
