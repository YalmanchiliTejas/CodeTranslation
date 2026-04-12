#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
#define MOD 1000000007
using ll = long long;
using namespace std;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int H, W;
vector<vector<char>> maze;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
cin >> H >> W;
maze.resize(H, vector<char>(W));
int s_cnt=0;
rep(i,H){
    rep(j,W){
        cin >> maze[i][j];
        if(maze[i][j]=='#'){
            s_cnt++;
        }
    }
}
if(s_cnt==H+W-1){
    cout << "Possible" << endl;
}
else{
    cout << "Impossible" << endl;
}

//system("pause");
return 0;
}