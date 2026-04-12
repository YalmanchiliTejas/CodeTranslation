#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int H,W,h,w,nh,nw,cnt;
vector<pair<int,int>> way={{0,1},{1,0}};

bool dfs(vector<string> &maze){
    queue<pair<int,int>> q;
    vector<vector<int>> visited(H,vector<int>(W,0));
    q.push(make_pair(0,0));
    visited[0][0]=1;
    while(!q.empty()){
        auto p=q.front();q.pop();
        h=p.first;w=p.second;
        cnt=0;
        for(auto np:way){
            nh=h+np.first;nw=w+np.second;
            if(nh>H-1||nw>W-1)continue;
            if(maze[nh][nw]=='.')continue;
            cnt++;
            if(nh==H-1&&nw==W-1){visited[nh][nw]=1;continue;}
            else{
                visited[nh][nw]=1;
                q.push(make_pair(nh,nw));
            }
        }
        if(cnt==2||cnt==0)return false;
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(maze[i][j]=='#'&&visited[i][j]==0)return false;
        }
    }
    return true;
}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    cin>>H>>W;
    vector<string> maze(H);
    for(int i=0;i<H;i++)cin>>maze[i];
    cout<<(dfs(maze)?"Possible":"Impossible")<<endl;
}
