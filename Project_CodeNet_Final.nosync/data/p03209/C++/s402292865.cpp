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
vec pa(51,-1);//Nレベルのバーガー丸ごと食べた時のパティの枚数

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
    if((eat >= (1LL << level+1) - 3) && pa.at(level) != -1){
        eat -= (1LL << level+1) - 3;
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
    if((eat >= (1LL << level+1) - 3) && pa.at(level) != -1){
        eat -= (1LL << level+1) - 3;
        ans += pa.at(level-1);
    }else{
        ans += dfs(level-1,eat);
    }
    if(eat == 0) return ans;
    //バン
    --eat;
    pa.at(level) = ans;
    return ans;
}

int main(){
    cin>>N>>K;
    pa.at(0) = 1;
    cout<<dfs(N,K)<<endl;
}
