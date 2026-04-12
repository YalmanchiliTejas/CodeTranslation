#include <bits/stdc++.h>
using namespace std;

#define IOS cin.tie(0);ios::sync_with_stdio(false)

#define ll      long long
#define Fi      first
#define Se      second
#define Pb      push_back
#define vi      vector<int>
#define vp      vector<pair<int,int>>
#define vvi     vector<vector<int>>
#define vvp     vector<vector<pair<int,int>>>

const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>; //Caution!! Segmentation Fault!! Don't forget to add +1!

#define all(v) v.begin(),v.end()
#define output_s(s) printf("%s\n",(s).c_str())

#define rep(i,n)        for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m)      for(int i=(int)(n);i<(int)(m);i++)
#define RepS(i,n,m)     for(int i=(int)(n);i<=(int)(m);i++)
#define RRepS(i,n,m)    for(int i=(int)(n);i>=(int)(m);i--)
#define RepA(x)         for(auto &item:(x))

void CINT(){} //@shibh308's template
template <class Head,class... Tail> void CINT(Head&& head,Tail&&... tail){cin>>head; CINT(move(tail)...);}    
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

void OUT(){}
template<class Head,class...Tail> void OUT(Head&& head,Tail&&...tail){cout<<head<<(sizeof...(tail)?' ':'\n'); OUT(move(tail)...);}
#define COUT(...) OUT(__VA_ARGS__)

template<typename TypeInt>TypeInt GCD(TypeInt a,TypeInt b){return a%b==0?b:GCD(b,a%b);} //最大公約数
template<typename TypeInt>TypeInt LCM(TypeInt a,TypeInt b){return a*b/GCD(a,b);}//最小公倍数

void YES(bool f){printf(f?"YES\n":"NO\n");}
void Yes(bool f){printf(f?"Yes\n":"No\n");}
void Possible(bool f){printf(f?"Possible\n":"Impossible\n");}
void POSSIBLE(bool f){printf(f?"POSSIBLE\n":"IMPOSSIBLE\n");}

//----------------------library------------------------//

//const int dx[4]={1,0,-1,0};
//const int dy[4]={0,1,0,-1};
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

const int NMAX = 200;
bool flag;

bool comp(int x,int y){
    return abs(0-x)<abs(0-y);
}

signed main(){
    IOS;
    CIN(H,W);
    vector<string> map(H);
    rep(i,H)cin>>map[i];
    vector<bool> row(H,false);
    vector<bool> colmn(W,false);
    rep(i,H){
        rep(j,W){
            if(map[i][j]=='#'){row[i]=true;colmn[j]=true;}
        }
    }
    rep(i,H){
        if(row[i]){
            rep(j,W){
                if(colmn[j])printf("%c",map[i][j]);
            }
            printf("\n");
        }
    }


    return 0;
}