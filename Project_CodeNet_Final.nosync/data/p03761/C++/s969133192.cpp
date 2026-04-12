#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){

    int n;
    cin >> n;
    string s[n];
    int cnt[n][26] = {0};
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < (int)s[i].size(); j++){
            cnt[i][s[i][j] - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++){
        int tmp = 100;
        for(int j = 0; j < n; j++){
            if(cnt[j][i] < tmp) tmp = cnt[j][i];
        }
        for(int k = 0; k < tmp; k++) cout << char('a' + i);
    }
    cout << endl;
    
    return 0;
}
