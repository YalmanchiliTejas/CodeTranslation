#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true; } return false; }

// const int INF = 1001001001;
// long long max => LLONG_MAX

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(26,0));
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < s.length(); j++){
            int c = (int)(s[j] - 'a');
            a[i][c]++;
        }
    }

    for(int i = 0; i < 26; i++){
        int minC = 100;
        for(int j = 0; j < n; j++){
            minC = min(minC, a[j][i]);
        }
        for(int k = 0; k < minC; k++){
            cout << (char)('a' + i);
        }
    }

    cout << endl;

    return 0;
}
