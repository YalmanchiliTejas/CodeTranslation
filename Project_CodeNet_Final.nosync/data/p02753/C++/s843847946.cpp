#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define SORT(v, n) sort(v, v+n)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define ddvi vector<vector<int>>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
// ここに処理を記述

    string S;

    cin >> S;
    if(S == "AAA" || S == "BBB") cout << "No" << "\n";
    else cout << "Yes" << endl;

return 0;
}