#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<string> S(n);
    vector<map<char,int>> ss(n);
    map<char,int> rs;

    rep(i,n)
        cin >> S.at(i);

    rep(i,n)
        rep(j, S.at(i).size()) {
            char c = S.at(i).at(j);
            if(ss.at(i).count(c))
                ss.at(i).at(c)++;
            else
                ss.at(i)[c] = 1;
        }


    for(auto p : ss.at(0))
        rs[p.first] = p.second;
    
    rep(i, n-1)
        for(auto p : rs)
            if(ss.at(i+1).count(p.first))
                rs.at(p.first) = min(rs.at(p.first), ss.at(i+1).at(p.first));
            else
                rs.erase(p.first);
    
    for(auto p : rs)
        rep(i, p.second)
            cout << p.first;
    cout << endl;
}