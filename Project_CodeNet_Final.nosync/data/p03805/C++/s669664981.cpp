#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<bool>> t;
vector<bool> already;
int n,m;
int ans=0;
void rec(int next){
    already[next]=true;
    bool b=true;
    for(int i=0;i<n;i++){
        if(!already[i])b=false;
    }
    if(b){
        ans++;
        already[next]=false;
        return;
    }
    for(int i=0;i<n;i++){
        if(next==i)continue;
        if(!already[i]&&t[next][i]){
            rec(i);
        }
    }
    already[next]=false;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    already=vector<bool>(n,false);
    for(int i=0;i<n;i++){
        t.push_back(vector<bool>(n,false));
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        t[a-1][b-1]=true;
        t[b-1][a-1]=true;
    }
    rec(0);
    cout<<ans<<endl;
    return 0;
}