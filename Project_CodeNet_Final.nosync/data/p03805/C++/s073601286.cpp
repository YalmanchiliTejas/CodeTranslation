#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int n;
void path (vector<vector<int>> g, int now, vector<int> past,vector<vector<int>> &a){

    if(past.size()==n){
        a.push_back(past);
        return;
    }

    for (auto i: g[now]){
            past.push_back(i);
            path(g,i,past,a);
            past.pop_back();
        }

}

int main(){
    cin>>n;
    int m; cin>>m;
    vector<vector<int>> g(n);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> past;
    past.push_back(0);
    vector<vector<int>> a;

    path(g,0,past,a);
    int count=0;

    rep(i,a.size()){
        sort(a[i].begin(),a[i].end());
        
        bool judge=true;
        rep(j,n-1){
            if(a[i][j]==a[i][j+1]) judge=false;
        }
        if(judge) count++;
    }
    cout<<count<<endl;
}