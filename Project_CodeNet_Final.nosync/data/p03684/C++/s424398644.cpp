#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) a.begin(),a.end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;

int par[100010];
int rrank[100010];
void init(int n){
for (int i=0;i<n;i++){
par[i]=i;
rrank[i]=0;
}}
int find(int x){
if (par[x]==x) return x;
else return par[x]=find(par[x]);
}
void unite(int x,int y){
x=find(x);
y=find(y);
if (x==y) return;
if (rrank[x]<rrank[y]) par[x]=y;
else {par[y]=x;
if (rrank[x]==rrank[y]) rrank[x]++;}}
bool same(int x,int y){
return find(x)==find(y);}

int main(){
    int n;
    cin >> n;
    vector<pp> x(n),y(n);
    vector<pair<int,pp>> a(0);
    rep(i,n){
        int f,g;
        cin >> f >> g;
        x.at(i)=make_pair(f,i);
        y.at(i)=make_pair(g,i);
    }
    sort(all(x));
    sort(all(y));
    rep(i,n-1){
        a.push_back(make_pair(x.at(i+1).first-x.at(i).first,make_pair(x.at(i).second,x.at(i+1).second)));
        a.push_back(make_pair(y.at(i+1).first-y.at(i).first,make_pair(y.at(i).second,y.at(i+1).second)));
    }
    init(n);
    sort(all(a));
    int ans=0;
    rep(i,a.size()){
        if (same(a.at(i).second.first,a.at(i).second.second)) continue;
        unite(a.at(i).second.first,a.at(i).second.second);
        ans+=a.at(i).first;
    }
    cout << ans << endl;
}