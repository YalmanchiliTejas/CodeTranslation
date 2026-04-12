#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long int;

ll solve1(string s, int l, int r) {
    s += '+'; r++;
    vector<ll> vs;

    ll val = 1;
    for(int i=l; i<r; i++) {
        if(s[i] == '*') continue;
        if(s[i] == '+') vs.emplace_back(val), val = 1;
        if(isdigit(s[i])) val *= (s[i] - '0');
    }

    return accumulate(vs.begin(), vs.end(), 0LL);
}

ll solve2(string s, int l, int r) {
    ll res = s[0] - '0';

    char op = '?';
    for(int i=1; i<r; i++) {
        if(isdigit(s[i])) {
            if(op == '*') res = res * (s[i] - '0');
            if(op == '+') res = res + (s[i] - '0');
        }
        else op = s[i];
    }
    return res;
}

int main() {
    string s; cin >> s;
    int N = s.size();
    ll res; cin >> res;

    ll v1 = solve1(s, 0, N);
    ll v2 = solve2(s, 0, N);
    
    if(v1 == res and v2 != res) cout << "M" << endl;
    else if(v2 == res and v1 != res) cout << "L" << endl;
    else if(v1 == res and v2 == res) cout << "U" << endl;
    else cout << "I" << endl;
    return 0;
}

