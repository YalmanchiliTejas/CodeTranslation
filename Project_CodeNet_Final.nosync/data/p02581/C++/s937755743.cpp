#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PP;
#define MOD 1000000007
//#define MOD 998244353
#define INF 2305843009213693951
//#define INF 810114514
#define PI 3.141592653589
#define setdouble setprecision
#define REP(i,n) for(ll i=0;i<(n);++i)
#define OREP(i,n) for(ll i=1;i<=(n);++i)
#define RREP(i,n) for(ll i=(n)-1;i>=0;--i)
#define all1(i) begin(i),end(i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false
#define debug2 false

const int MEM = 2010;
ll dp[MEM][MEM]={};
ll mx[MEM]={};
ll mxa;

vector<pair<pair<ll,ll>,ll>> change;

void chmax(pair<ll,ll> X,ll Y){
    change.push_back({X,Y});
}

//in-placeの更新遅延
void reflect(void){
    REP(i,change.size()){
        pair<ll,ll> X=change[i].first;
        ll Y=change[i].second;
        
        if(dp[X.first][X.second]<Y){
            
            dp[X.first][X.second]=Y;
            dp[X.second][X.first]=Y;
            mx[X.first]=max(mx[X.first],dp[X.first][X.second]);
            mx[X.second]=max(mx[X.second],dp[X.second][X.first]);
            mxa=max(mxa,mx[X.first]);
            mxa=max(mxa,mx[X.second]);
        }
    }
    change.clear();
}
    
int main(void){
    ll N,p,q,r;
    ll Ans=0;
    vector<array<ll,3>> A;
    
    cin >> N;
    cin >> p >> q;
    p--;q--;
    REP(i,N-1){
        array<ll,3> a;
        cin >> a[0] >> a[1] >> a[2];
        REP(j,3){a[j]--;}
        sort(a.begin(),a.end());
        A.push_back(a);
    }
    cin >> r;r--;
    
    
    REP(i,MEM){REP(j,MEM){dp[i][j]=-INF;}}
    REP(i,MEM){mx[i]=-INF;}
    
    dp[p][q]=0;dp[q][p]=0;
    mx[p]=0;mx[q]=0;
    mxa=0;
    
    
    REP(i,A.size()){
        array<ll,3> D = A[i];
        
        //パターン1 (来たやつ全部いっしょ)
        if(D[0]==D[2]){
            Ans++;
            continue;
        }
        //パターン2 (来たやつ2ついっしょ)
        if(D[0]==D[1]){
            REP(j,N){
                chmax({j,D[2]},dp[j][D[0]]+1);
            }
        }
        if(D[1]==D[2]){
            REP(j,N){
                chmax({j,D[0]},dp[j][D[2]]+1);
            }
        }
        //パターン3 (来たやつ全部違う)
        chmax({D[1],D[2]},dp[D[0]][D[0]]+1);
        chmax({D[0],D[2]},dp[D[1]][D[1]]+1);
        chmax({D[0],D[1]},dp[D[2]][D[2]]+1);
        
        
        //ここからは得にならない遷移
        //パターン4 (来たやつそのまま受け流す(ナベアツ))
        //in-placeにつきコード不要
        
        //パターン5 (来たやつ1つ受け取る)
        REP(j,N){
            REP(k,3){
                chmax({j,D[k]},mx[j]);
            }
        }
        //パターン6 (来たやつ2つ受け取る)
        chmax({D[0],D[1]},mxa);
        chmax({D[0],D[2]},mxa);
        chmax({D[1],D[2]},mxa);
        
        reflect();
        
    }
    //最後の1回
    chmax({r,r},dp[r][r]+1);
    reflect();
    
    Ans+=mxa;
    cout << Ans << endl;
    
    return 0;
}

