#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int MOD = 1000000007;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

int bin(string s){
    int n = s.size();
    int ans = 1;
    repp(i,n,1){
        if (s[i] == '0') ans = 2 * ans;
        else ans = 2 * ans + 1;
    }
    return ans;
}

int main(){
    int n, m; cin >> n >> m;
    if (n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
}