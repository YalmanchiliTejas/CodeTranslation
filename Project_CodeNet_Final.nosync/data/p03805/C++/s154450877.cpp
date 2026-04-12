/*  .　　∧_∧
   　（ ´・ω・)
   　//＼￣￣旦＼
   ／/ ※ ＼＿＿＿＼
   ＼＼ 　※ 　※ 　※ ヽ
   　 ＼ヽ-＿_＿--＿__ヽ*/
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define sort(v,n) sort(v,v+n);
#define vsort(v) sort(v.begin(),v.end());
#define vvsort(v) sort(v.begin(),v.end(),greater<int>());
#define ll long long
#define pb(a) push_back(a)
#define fi first
#define se second
#define inf 999999999
using namespace std;
typedef pair<int,int> p;
typedef pair<ll,ll> lp;
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int> > rpq;
bool is_uruu(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}
const ll MOD=1e9+7;
const double PI=acos(-1.0);
//----------------------------------------------------------------------------------------------------------------------------------//
int n,m;
int g[10][10];
int pp[10];
int main(){
        cin>>n>>m;
        while(m--) {
                int x,y;
                cin>>x>>y;
                x--; y--;
                g[x][y]=g[y][x]=1;
        }
        for(int i=0; i<n; i++) {
                pp[i]=i;
        }
        int ans=0;
        do {
                bool flag=true;
                if(pp[0]!=0) continue;
                for(int i=1; i<n; i++) {
                        if(g[pp[i-1]][pp[i]]!=1) {
                                flag=false;
                                break;
                        }
                }
                if(flag) ans++;
        } while(next_permutation(pp,pp+n));
        cout<<ans<<endl;
}
