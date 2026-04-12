#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;

vector<vector<int> > v(9);
int n,m,ans=0;
void solve(int,int,vector<int>);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    vector<int> maki;
    maki.pb(1);
    solve(1,1,maki);
    cout << ans<<endl;
    return 0;
}

void solve(int a,int index,vector<int> s){
    if(index==n){
        ans++;
        return;
    }
    s.pb(a);
    index++;
    for(int i=0;i<v[a].size();i++){
        bool maki=true;
        for(int j=0;j<s.size();j++){
            if(v[a][i]==s[j]){
                maki=false;
            }
        }
        if(maki==true){
            solve(v[a][i],index,s);
        }
    }
    return;
}

