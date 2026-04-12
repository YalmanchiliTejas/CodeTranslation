#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

template<class T,class U>constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}
template<class T,class U>constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}
#define bit(n,k) ( (n>>k)&1 )

//デバッグ
template<class T>
void Vout(vector<T> &V){
    cout<<"\nstart\n";
    const int sz=V.size();
    for(int i=0;i<sz;i++){
        cout<<i<<" "<<V[i]<<'\n';
    }
    cout<<"end\n"<<endl;
}

template<class T>
void VPout(vector<T> &V){
    cout<<"\nstart\n";
    const int sz=V.size();
    for(int i=0;i<sz;i++){
        cout<<i<<" "<<V[i].first<<" "<<V[i].second<<'\n';
    }
    cout<<"end\n"<<endl;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


constexpr int MAX=1<<30;
constexpr ll INF=1LL<<62;
constexpr int MOD=1e9+7;
int dx[]={1,-1,0,0},dy[]={0,0,-1,1};

//__builtin_popcount(S);
//#define int ll
//vector<vector<int>> data(3, vector<int>(4));
//vector.resize(a,vector<int>(b,-1));
//vector<vector<vector<要素の型>>> 変数名(要素数1, vector<vector<要素の型>>(要素数2, vector<要素の型>(要素数3, 初期値)));


ll dp[110][5][3];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    string N;
    int K;
    cin>>N>>K;
    dp[0][0][0]=1;
    for(int i=0;i<(int)N.size();i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<3;k++){
                if(dp[i][j][k]==0) continue;
                if(k==2){
                    dp[i+1][j+1][2]+=dp[i][j][2]*9;
                    dp[i+1][j][2]+=dp[i][j][2];       
                }else if(k==1){
                    int x=(int)( N[i]-'0' );
                    if(x==0){
                        dp[i+1][j][1]+=dp[i][j][k];
                    }else{
                        dp[i+1][j][2]+=dp[i][j][k];
                        dp[i+1][j+1][2]+=dp[i][j][k]*(x-1);
                        dp[i+1][j+1][1]+=dp[i][j][k];
                    }
                }else{
                    dp[i+1][j][k]+=dp[i][j][k];
                    if(i==0){
                        int x=(int)( N[i]-'0' );
                        dp[i+1][j+1][2]+=dp[i][j][k]*(x-1);
                        dp[i+1][j+1][1]+=dp[i][j][k];
                    }else{
                        dp[i+1][j+1][2]+=dp[i][j][k]*9;
                    }
                }
            }
        }
    }
    cout<<dp[(int)N.size()][K][1]+dp[(int)N.size()][K][2]<<endl;
}