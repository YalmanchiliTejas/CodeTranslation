#include <bits/stdc++.h>
using namespace std;

#define IOS cin.tie(0);ios_base::sync_with_stdio(false)

#define ll      long long
#define Fi      first
#define Se      second
#define Pb      push_back
#define vi      vector<int>
#define vs      vector<string>
#define vp      vector<pair<int,int>>
#define vvi     vector<vector<int>>
#define vvp     vector<vector<pair<int,int>>>
using Graph  =  vector<vector<int>>; //Caution!! Segmentation Fault!! Don't forget to add +1!

#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define output_s(s) printf("%s\n",(s).c_str())
#define END cout<<"\n"

#define rep(i,n)        for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m)      for(int i=(int)(n);i<(int)(m);i++)
#define RepS(i,n,m)     for(int i=(int)(n);i<=(int)(m);i++)
#define RRepS(i,n,m)    for(int i=(int)(n);i>=(int)(m);i--)
#define SRepS(i,n,m)    for(int i=(int)(n);i*i<=(int)(m);i++)
#define RepA(x)         for(auto &item:(x))

void CINT(){} //@shibh308's template
template<class Head,class... Tail> void CINT(Head&& head,Tail&&... tail){cin>>head; CINT(move(tail)...);}    
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
#define VCIN(x) for(auto &item:x) cin>>item

void OUT(){}
template<class Head,class...Tail> void OUT(Head&& head,Tail&&...tail){cout<<head<<(sizeof...(tail)?" ":"\n"); OUT(move(tail)...);}
#define COUT(...) OUT(__VA_ARGS__)

template<typename TypeInt>TypeInt GCD(TypeInt a,TypeInt b){return a%b==0?b:GCD(b,a%b);} //最大公約数
template<typename TypeInt>TypeInt LCM(TypeInt a,TypeInt b){return a*b/GCD(a,b);} //最小公倍数
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
template<class T>bool comp(T a,T b){return abs(a)<abs(b);} //比較関数

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
const int INF = 1e9;
const int MOD = 1e9+7;
bool flag;

//----------------------Global-------------------------//

signed main(){
    CIN(N);
    map<char,int> mp;
    SCIN(s);
    RepA(s)mp[item]++;
    rep(i,N-1){
        map<char,int> cur;
        SCIN(S);
        RepA(S)cur[item]++;
        RepA(mp) chmin(item.second,cur[item.first]);
    }
    RepA(mp)rep(i,item.second)printf("%c",item.first);
    END;


    return 0;
}