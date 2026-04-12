#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> S_list(n, vector<int>(26, 0));

    REP(i,n){
        string tmp;
        cin >> tmp;

        for(char c : tmp){
            int index = (int)(c - 'a');
            S_list[i][index]++;
        }
    }

    vector<int> ans(26,0);
    REP(i,26){
        int min_c = S_list[0][i];
        for(int j=0; j<n; j++){
            chmin(min_c, S_list[j][i]);
        }
        ans[i] = min_c;
    }

    string ans_S = "";
    REP(i, 26){
        for(int j=0; j<ans[i]; j++){
            ans_S += 'a' + i;
        }
    }

    cout << ans_S << endl;

    return 0;
}