#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=1<<16,INF=1<<30;
vector<int> A,B;
int dis[MAX];

void BFS(){
    queue<int> Q;
    Q.push(0);
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        
        for(int i=0;i<si(A);i++){
            int v=u;
            v&=A[i];
            v|=B[i];
            if(chmin(dis[v],dis[u]+1)){
                Q.push(v);
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    dis[0]=0;
    for(int i=1;i<(1<<16);i++) dis[i]=INF;
    
    set<int> SE;
    for(int i=0;i<N;i++){
        int h,w;cin>>h>>w;
        for(int uh=-3;uh<=3;uh++){
            for(int uw=-3;uw<=3;uw++){
                int nuru=0;
                for(int dh=0;dh<h;dh++){
                    for(int dw=0;dw<w;dw++){
                        int toh=uh+dh,tow=uw+dw;
                        if(toh<0||toh>=4||tow<0||tow>=4) continue;
                        nuru|=(1<<(toh*4+tow));
                    }
                }
                SE.insert(nuru);
            }
        }
    }
    
    vector<string> S(4);
    for(int i=0;i<4;i++) cin>>S[i];
    
    string T="RGB";
    
    for(int a:SE){
        for(int k=0;k<3;k++){
            int x=(1<<16)-1;
            x^=a;
            A.push_back(x);
            
            x=0;
            
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(!(a&(1<<(i*4+j)))) continue;
                    if(T[k]!=S[i][j]) continue;
                    x|=1<<(i*4+j);
                }
            }
            
            B.push_back(x);
        }
    }
    
    BFS();
    
    cout<<dis[(1<<16)-1]<<endl;
}


