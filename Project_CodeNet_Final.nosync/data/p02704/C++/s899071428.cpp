#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=55,MAX2=2600;
const ll INF=1LL<<59;
typedef vector<vector<ll>> mat;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937_64 rng(58);
    
    int N;cin>>N;
    mat ans(N,vector<ll>(N));
    
    mat S(4,vector<ll>(N));
    
    for(int i=0;i<4;i++){
        for(int j=0;j<N;j++){
            cin>>S[i][j];
        }
    }
    swap(S[1],S[2]);
    bool ok=true;
    
    for(int q=0;q<2;q++){
        for(int z=0;z<64;z++){
            mat T(N,vector<ll>(N,2));
            mat che(2,vector<ll>(N,0));
            for(int j=0;j<N;j++){
                if(S[0][j]==0&&(S[1][j]&(1uLL<<z))){
                    for(int k=0;k<N;k++){
                        if(T[j][k]==0) ok=false;
                        T[j][k]=1;
                        che[0][j]=1;
                    }
                }
                if(S[0][j]==1&&(!(S[1][j]&(1uLL<<z)))){
                    for(int k=0;k<N;k++){
                        if(T[j][k]==1) ok=false;
                        T[j][k]=0;
                        che[0][j]=1;
                    }
                }
                if(S[2][j]==0&&(S[3][j]&(1uLL<<z))){
                    for(int k=0;k<N;k++){
                        if(T[k][j]==0) ok=false;
                        T[k][j]=1;
                        che[1][j]=1;
                    }
                }
                if(S[2][j]==1&&(!(S[3][j]&(1uLL<<z)))){
                    for(int k=0;k<N;k++){
                        if(T[k][j]==1) ok=false;
                        T[k][j]=0;
                        che[1][j]=1;
                    }
                }
            }
            
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(S[0][i]==0&&!(S[1][i]&(1uLL<<z))){
                        if(S[2][j]==0&&!(S[3][j]&(1uLL<<z))){
                            T[i][j]=0;
                            che[0][i]=1;
                            che[1][j]=1;
                        }
                    }
                    
                    if(S[0][i]==1&&(S[1][i]&(1uLL<<z))){
                        if(S[2][j]==1&&(S[3][j]&(1uLL<<z))){
                            T[i][j]=1;
                            che[0][i]=1;
                            che[1][j]=1;
                        }
                    }
                }
            }
            
            for(int i=0;i<N;i++){
                if(!che[0][i]) continue;
                for(int j=0;j<N;j++){
                    if(T[i][j]!=2) continue;
                    
                    if(S[2][j]==0){
                        T[i][j]=0;
                        che[1][j]=1;
                    }else{
                        T[i][j]=1;
                        che[1][j]=1;
                    }
                }
            }
            
            for(int j=0;j<N;j++){
                if(!che[1][j]) continue;
                for(int i=0;i<N;i++){
                    if(T[i][j]!=2) continue;
                    
                    if(S[0][i]==0){
                        T[i][j]=0;
                        che[0][i]=1;
                    }else{
                        T[i][j]=1;
                        che[0][i]=1;
                    }
                }
            }
            int X=q;
            for(int i=0;i<N;i++){
                int cnt=X;
                for(int j=0;j<N;j++){
                    if(T[i][j]!=2) continue;
                    
                    T[i][j]=cnt&1;
                    cnt++;
                }
                if(cnt!=X) X++;
            }
            
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    ans[i][j]+=((1uLL<<z)*T[i][j]);
                }
            }
        }
        
        bool check=true;
        for(int i=0;i<N;i++){
            ll now;
            if(S[0][i]==0){
                now=-1;
                for(int j=0;j<N;j++){
                    now&=ans[i][j];
                }
            }else{
                now=0;
                for(int j=0;j<N;j++){
                    now|=ans[i][j];
                }
            }
            if(now!=S[1][i]) check=false;
        }
        
        for(int j=0;j<N;j++){
            ll now;
            if(S[2][j]==0){
                now=-1;
                for(int i=0;i<N;i++){
                    now&=ans[i][j];
                }
            }else{
                now=0;
                for(int i=0;i<N;i++){
                    now|=ans[i][j];
                }
            }
            if(now!=S[3][j]) check=false;
        }
        
        if(check) break;
        else{
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    ans[i][j]=0;
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        ll now;
        if(S[0][i]==0){
            now=-1;
            for(int j=0;j<N;j++){
                now&=ans[i][j];
            }
        }else{
            now=0;
            for(int j=0;j<N;j++){
                now|=ans[i][j];
            }
        }
        if(now!=S[1][i]) ok=false;
    }
    
    for(int j=0;j<N;j++){
        ll now;
        if(S[2][j]==0){
            now=-1;
            for(int i=0;i<N;i++){
                now&=ans[i][j];
            }
        }else{
            now=0;
            for(int i=0;i<N;i++){
                now|=ans[i][j];
            }
        }
        if(now!=S[3][j]) ok=false;
    }
    
    if(!ok) cout<<-1<<endl;
    else{
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
