#include<bits/stdc++.h>
using namespace std;

using ll= long long;
const ll INF=1LL<<60;
const ll MOD=1000000007;

template<class T>
bool chmax(T &a, const T &b){
    if(a < b){
        a=b;
        return 1;
    }
    return 0;
}
template<class T>
bool chmin(T &a, const T &b){
    if(a > b){
        a=b;
        return 1;
    }
    return 0;
}

int N;
vector<vector<ll>> dp;
deque<int> a;

ll rec(int l=0, int r=N, int turn=1){
    int x=a.front();
    int y=a.back();
    if(turn == 1) turn=0;
    else turn=1;
    if(r-l <= 1) return x*(1-turn)-x*turn; 
    if(r-l <= 2){
        if(turn == 0) return max(x, y)-min(x,y);
        else return -max(x,y)+min(x,y);
    }
    ll &ret=dp[l][r];
    if(ret != -1) return ret;
    if(turn == 0){
        a.pop_front();
        ret=rec(l+1, r, turn)+x;
        a.push_front(x);
        a.pop_back();
        chmax(ret, rec(l, r-1, turn)+y);
        a.push_back(y);
    }
    else{
        a.pop_front();
        ret=rec(l+1, r, turn)-x;
        a.push_front(x);
        a.pop_back();
        chmin(ret, rec(l, r-1, turn)-y);
        a.push_back(y);
    }
    return ret;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    dp.assign(N+1, vector<ll>(N+1, -1));
    ll ans=rec();
    cout << ans << endl;
    return 0;
}