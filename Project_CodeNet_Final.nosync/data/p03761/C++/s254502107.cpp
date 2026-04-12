#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    vector<map<char,int>> d(n);
    rep(i,n){
        string s;
        cin >> s;
        rep(j,s.size()){
            d[i][s[j]]++;
        }
    }
    map<char,int> m = d[0];
    for(auto x:m){
        char k = x.first;
        rep(i,n) m[k] = min(m[k],d[i][k]);
    }
    for(auto x:m){
        rep(i,x.second) cout << x.first;
    }
    cout << endl;
}