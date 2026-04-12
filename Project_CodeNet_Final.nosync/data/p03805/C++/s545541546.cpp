#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    auto a = vector<int>(m,0);
    auto b = vector<int>(m,0);
    auto c = vector<vector<int> >(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i];
        c[--a[i]][--b[i]] = 1;
        c[b[i]][a[i]] = 1;
    }
    
    stack<pair<int,int> > s;
    s.push(make_pair(0,0));
    int ans = 0;
    while(!s.empty()){
        auto u=s.top();
        bool t = false;
        s.pop();
        u.second |= 1<<u.first;
        //cout << u.first << " "<<bitset<8>(u.second) << endl;
        for(int i=0;i<n;i++){
            if(u.second & 1<<i) continue;
            if(c[u.first][i]==0) continue;
            s.push(make_pair(i,u.second));
            t=true;
        }
        if(!t&&u.second==(int)pow(2,n)-1){
            ans++;
        }
    }
    
    cout << ans;
    
}