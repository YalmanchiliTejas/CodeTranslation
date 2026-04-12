#include <bits/stdc++.h>
using namespace std;
#define dg(x) cerr << #x << " = " << x <<endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,m;
bool G[10][10];
int main(){
#ifdef LOCAL
    //freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
    #define endl '\n'
#endif
    cin>>n>>m;
    forn(i,m){
        int u,v;
        cin>>u>>v;
        G[u][v]=1;
        G[v][u]=1;
    }
    string path="";
    fore(i,2,n)path+='0'+i;
    ll cnt=0;
    do{
        bool ok=1;
        int last=1;
        forn(i,n-1){
            if(!G[path[i]-'0'][last]){
                ok=0;
                break;
            }
            last=path[i]-'0';

        }
        if(ok)cnt++;
    }while(next_permutation(all(path)));
    cout<<cnt<<endl;
    return 0;
}