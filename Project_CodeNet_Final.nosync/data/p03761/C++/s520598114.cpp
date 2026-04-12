#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    map<char, int> ans;
    for(char c = 'a'; c <= 'z'; c++){
        ans[c] = 50;
    }

    rep(i, n){
        string s;
        cin >> s;
        map<char, int> cnt;
        for(char c = 'a'; c <= 'z'; c++){
            cnt[c] = 0;
        }
        rep(j, (int)s.size()){
            cnt[s[j]]++;
        }
        for(auto itr = cnt.begin(); itr != cnt.end(); itr++){
            ans[itr->first] = min(ans[itr->first], itr->second);
        }
    }

    for(auto itr = ans.begin(); itr != ans.end(); itr++){
        rep(i, itr->second) cout << itr->first;
    }
    cout << endl;
    
}