#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    copy_n(istream_iterator<string>(cin), n, S.begin());
    
    map<char, int> C;
    const constexpr int INF = 1e6;
    for (char a = 'a'; a <= 'z'; a++)
        C[a] = INF;
    for (const auto &s: S){
        map<char, int> D;
        for (const auto &c: s)
            D[c]++;
        for (const auto &c: C)
            C[c.first] = min(C[c.first], D[c.first]);
    }

    string T = "";
    for (const auto &c: C)
        T += string(c.second, c.first);

    cout << T << endl;
}