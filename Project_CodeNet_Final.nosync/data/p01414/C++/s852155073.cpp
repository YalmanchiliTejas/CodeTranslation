#include "bits/stdc++.h"

using namespace std;

typedef pair<int,int> P;
const int INF = numeric_limits<int>::max()/2;

int n;
vector<P> stmp;
vector<vector<int>> col(4,vector<int>(4));
vector<int> dis(1<<16,INF);

int solve(){
    queue<int> q;
    dis[0]=0;
    q.push(0);
    while(!q.empty()){
        int prev=q.front();q.pop();
        for(int i=0;i<n;i++){
            for(int j=0;j<=2;j++){
                // stamp[i] with color_j
                int h=stmp[i].first,w=stmp[i].second;
                for(int sx=1-h;sx<4;sx++){
                    for(int sy=1-w;sy<4;sy++){

                        int next=prev;
                        for(int ni=max(0,-sx);ni<min(h,4-sx);ni++){
                            for(int nj=max(0,-sy);nj<min(w,4-sy);nj++){
                                int nx=sx+ni,ny=sy+nj;
                                if(nx<0 || 4<=nx || ny<0 || 4<=ny) continue;
                                int num=15-4*nx-ny;
                                if(col[nx][ny]==j) next |= (1<< num);
                                else next &= ~(1<<num); 
                            }
                        }

                        if(dis[next]!=INF) continue;
                        dis[next]=dis[prev]+1;
                        if(next==((1<<16)-1)) return dis[next];
                        q.push(next);
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++){
        int h,w;cin>>h>>w;
        stmp.push_back(P(h,w));
    }
    for(int i=0;i<4;i++){
        string s;cin>>s;
        for(int j=0;j<4;j++){
            if(s[j]=='R') col[i][j]=0;
            else if(s[j]=='G') col[i][j]=1;
            else col[i][j] = 2;
        }
    }
    cout<<solve()<<endl;
}
