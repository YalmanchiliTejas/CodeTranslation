// Created by sz
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    set<char> ss;
    for (auto i : s) {
        ss.insert(i);
    }
    
    if(ss.size()>1)cout << "Yes" << "\n";
    else cout << "No" << "\n";
    
    return 0;
}
