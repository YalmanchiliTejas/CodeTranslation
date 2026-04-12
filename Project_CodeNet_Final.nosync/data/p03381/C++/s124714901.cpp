#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
#define REP(i, x, n) for(lint i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(lint i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())

const int IINF = 1e9 + 10;
const lint LLINF = (lint)1e18 + 10;
const lint MOD = (lint)1e9 + 7;
const lint inv = MOD - 2;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

typedef pair<int, int> P;

int main(){
    int n;
    cin >> n;
    vector<P> x(n);
    rep(i, n){
        cin >> x[i].first;
        x[i].second = i;
    }
    SORT(x);
    vector<int> ans(n);
    rep(i, n){
        if(i < n/2){
            ans[x[i].second] = x[n/2].first;
        }else{
            ans[x[i].second] = x[n/2-1].first;
        }
    }
    rep(i, n){
        cout << ans[i] << endl;
    }
    return 0;
}