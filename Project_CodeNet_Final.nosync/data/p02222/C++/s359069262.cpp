#include"bits/stdc++.h"
using namespace std;
typedef long long ll;


vector<vector<int>> v(100010);
int r,now;

void dfs(int p,int pre,int d){
    if(now < d){
        now = d;
        r = p;
    }
    for(auto i:v[p]){
        if(pre != i){
            dfs(i,p,d+1);
        }
    }
}

bool used[100010];
vector<int> d;
bool go(int p,int pre){
    bool ret = false;
    if(p == r){
        d.push_back(p);
        used[p] = 1;
        return true;
    }
    for(auto i:v[p]){
        if(i != pre){
            ret |= go(i,p);
            if(ret)break;
        }
    }
    if(ret){
        used[p] = 1;
        d.push_back(p);
    }
    return ret;
}

int ma = 0;

void solve(int p,int pre,int d,bool wa){
    if(!wa || d!=now)ma = max(d,ma);
    else ma = max(d-1,ma);
    for(auto i:v[p]){
        if(i != pre && !used[i]){
            solve(i,p,d+1,wa);
        }
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0,-1,0);
    int r1=r;
    r=-1,now=-1;
    dfs(r1,-1,0);
    int r2 = r;
    // cout << r1 << " " << r2 << endl;
    go(r1,-1);
    string ans = "";
    for(int i=0;i<n;i++){
        ans += "1";
    }
    if(now == n-1){
        cout << ans << endl;
        return 0;
    }
    // d: r2 -> r1
    for(int i=0;i<d.size();i++){
        if(v[d[i]].size() > 2){
            //cerr << "a " << i << " " << d[i] << endl;
            solve(d[i],-1,max(i,now-i),(i==(now-i)));
        }
    }
    // cerr << ma << endl;
    // ma = min(ma,now);
    for(int i=2;i<ma;i++){
        ans[i] = '0';
    }
    cout << ans << endl;



}
