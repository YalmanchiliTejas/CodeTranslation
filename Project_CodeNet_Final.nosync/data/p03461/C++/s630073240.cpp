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
const int mod=1000000007,MAX=305,INF=1<<30;

int dis[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int A,B;cin>>A>>B;
    int N=16*16+1;
    int M=15*17+16*16;
    
    vector<pair<int,int>> ans;
    
    for(int i=0;i<256;i+=16){
        for(int j=0;j<15;j++){
            ans.push_back(mp(i+j,i+j+1));
        }
    }
    
    for(int i=0;i+16<256;i+=16) ans.push_back(mp(i,i+16));
    
    for(int i=0;i<256;i++) ans.push_back(mp(i,256));
    
    vector<vector<int>> S(A+1,vector<int>(B+1));
    
    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            cin>>S[i][j];
            
            for(int a=0;a<16;a++){
                for(int b=0;b<16;b++){
                    int sum=a*i+b*j;
                    chmax(dis[16*b+a][256],S[i][j]-sum);
                }
            }
        }
    }
    
    bool ok=true;
    
    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            int mini=INF;
            
            for(int a=0;a<16;a++){
                for(int b=0;b<16;b++){
                    chmin(mini,a*i+b*j+dis[16*b+a][256]);
                }
            }
            
            if(mini!=S[i][j]) ok=false;
        }
    }
    
    if(ok){
        cout<<"Possible\n";
        cout<<N<<" "<<M<<endl;
        for(int i=0;i<M;i++){
            cout<<ans[i].fi+1<<" "<<ans[i].se+1<<" ";
            if(ans[i].se==256) cout<<dis[ans[i].fi][256]<<"\n";
            else if(ans[i].se-ans[i].fi==1) cout<<"X\n";
            else if(ans[i].se-ans[i].fi==16) cout<<"Y\n";
        }
        cout<<1<<" "<<257<<endl;
    }else if(A==1){
        ok=true;
        for(int j=2;j<=B;j++){
            if(S[1][1]*j!=S[1][j]) ok=false;
        }
        if(ok){
            cout<<"Possible\n";
            cout<<S[1][1]+1<<" "<<S[1][1]<<endl;
            for(int i=1;i<=S[1][1];i++){
                cout<<i<<" "<<i+1<<" "<<"Y\n";
            }
            cout<<1<<" "<<S[1][1]+1<<"\n";
        }else{
            cout<<"Impossible\n";
        }
    }else if(B==1){
        ok=true;
        for(int j=2;j<=A;j++){
            if(S[1][1]*j!=S[j][1]) ok=false;
        }
        if(ok){
            cout<<"Possible\n";
            cout<<S[1][1]+1<<" "<<S[1][1]<<endl;
            for(int i=1;i<=S[1][1];i++){
                cout<<i<<" "<<i+1<<" "<<"X\n";
            }
            cout<<1<<" "<<S[1][1]+1<<"\n";
        }else{
            cout<<"Impossible\n";
        }
    }else{
        cout<<"Impossible\n";
    }
    
}
