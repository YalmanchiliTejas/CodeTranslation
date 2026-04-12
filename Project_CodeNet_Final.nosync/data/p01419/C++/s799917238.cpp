#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=53,INF=1<<20;
int H,W,Q,t=1;
int costuse[MAX][MAX],coston[MAX][MAX],costoff[MAX][MAX];
vector<int> when[MAX][MAX];
bool room[MAX][MAX];

vector<int> dh={0,1,0,-1},dw={1,0,-1,0};

bool DFS(pair<int,int> u,pair<int,int> p,pair<int,int> g){
    if(u==g){
        return 1;
    }
    for(int k=0;k<4;k++){
        int toh=u.first+dh[k],tow=u.second+dw[k];
        
        if(!room[toh][tow]) continue;
        if(toh==p.first&&tow==p.second) continue;
        
        if(DFS({toh,tow},u,g)){
            when[u.first][u.second].push_back(t);
            t++;
            
            return 1;
        }
    }
    
    return 0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>H>>W>>Q;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char c;cin>>c;
            if(c=='.') room[i+1][j+1]=1;
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>costuse[i+1][j+1];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>coston[i+1][j+1];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>costoff[i+1][j+1];
        }
    }
    
    vector<int> h(Q),w(Q);
    
    for(int i=0;i<Q;i++){
        cin>>h[i]>>w[i];
        h[i]++;
        w[i]++;
    }
    
    when[h[0]][w[0]].push_back(0);
    
    for(int i=1;i<Q;i++){
        DFS({h[i],w[i]},{-1,-1},{h[i-1],w[i-1]});
    }
    
    ll ans=0;
    
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(when[i][j].size()==0) continue;
            ans+=coston[i][j]+costoff[i][j];
            for(int k=1;k<when[i][j].size();k++){
                ans+=min(ll((when[i][j][k]-when[i][j][k-1]))*costuse[i][j],ll(coston[i][j]+costoff[i][j]));
            }
        }
    }
    
    cout<<ans<<endl;
}

