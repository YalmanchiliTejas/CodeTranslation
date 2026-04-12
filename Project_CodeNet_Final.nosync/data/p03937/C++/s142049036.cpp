#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

int n,m;

string s[10];

bool vis[10][10];

void dfs(int x,int y){
    if(s[x][y] != '#')
        return;
    if(vis[x][y])
        return;
    vis[x][y] = 1;
    if(x < n)
        dfs(x+1,y);
    if(y < m)
        dfs(x,y+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0 ; i<n ;i ++){
        cin>>s[i];
    }

    dfs(0,0);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(!vis[i][j] &&s[i][j] == '#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(s[i][j] == '#'){
                if(i+1 < n && s[i+1][j] == '#' && j+1 < m && s[i][j+1] == '#'){
                cout<<"Impossible"<<endl;
                return 0;
                }
            }
        }
    }
    cout<<"Possible"<<endl;

    return 0;
}
