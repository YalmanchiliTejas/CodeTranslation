#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,A,B;
string S;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vec pa(51,-1),num(51,-1);

ll dfs(ll level, ll &eat){
    if(eat == 0) return 0;
    if(level == 0){
        --eat;
        return 1;
    }
    ll ans = 0;
    //バン
    --eat;
    if(eat == 0) return ans;
    //N-1レベル
    if(eat >= num.at(level-1)){
        eat -= num.at(level-1);
        ans += pa.at(level-1);
    }else{
        ans += dfs(level-1,eat);
    }
    if(eat == 0) return ans;
    //パティ
    --eat;
    ++ans;
    if(eat == 0) return ans;
    //N-1レベル
    if(eat >= num.at(level-1)){
        eat -= num.at(level-1);
        ans += pa.at(level-1);
    }else{
        ans += dfs(level-1,eat);
    }
    if(eat == 0) return ans;
    //バン
    --eat;
    return ans;
}

int main(){
    cin>>N>>K;
    rep(i,51){
        pa.at(i) = (1LL<<(i+1))-1;
        num.at(i) = (1LL<<(i+2))-3;
    }
    cout<<dfs(N,K)<<endl;
}
