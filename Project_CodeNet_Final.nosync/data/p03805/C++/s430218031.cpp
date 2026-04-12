#include <bits/stdc++.h>
using namespace std;
#define ll unsighned long int

int ans = 0;



void solve(int n,vector<vector<int> > v,vector<int> dist,int pos = 1,int k = 1){
    //cout << ans << endl;
    if(k == n){
        ans++;
        return ;
    }
    for(int i = 0; i < v[pos - 1].size(); ++i){
        if(dist[v[pos - 1][i] - 1] != 1){
            dist[v[pos - 1][i] - 1] = 1;
            solve(n,v,dist,v[pos - 1][i],k + 1);
            dist[v[pos - 1][i] - 1] = -1;
        }
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    //cout << n << " " << m << endl;

    vector<vector<int> > v(n);

    vector<int> dist(n,-1);


    dist[0] = 1;

    for(int i = 0; i < m; ++i){
        int a,b;
        cin >> a >> b;
        v[a - 1].push_back(b);
        v[b - 1].push_back(a);
    }
    solve(n,v,dist);
    cout << ans << endl;
}