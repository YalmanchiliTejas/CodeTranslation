#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>

using namespace std;

#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
const int MOD = 1e9 + 7;



int main() {
    int n;
    cin >> n;
    vs S(n);
    vector<char> alp = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    map<char, int> ans;
    for (char x : alp) {
        ans[x] = 100;
    }
    rep(i, n) cin >> S[i];
    rep(i, n) {
        vi anss(26,0);
        rep(k, 26) {
                rep(j, S[i].size()) {
                if (S[i].at(j) == alp[k]) {
                    anss[k]++;
                }
            }
            if (anss[k] < ans[alp[k]]) ans[alp[k]] = anss[k];
        }
    }
    string answer = "";
    for (int i = 0; i < 26; i++) {
        rep(j, ans[alp[i]]) answer = answer + alp[i];
    }
    cout << answer << endl;
}