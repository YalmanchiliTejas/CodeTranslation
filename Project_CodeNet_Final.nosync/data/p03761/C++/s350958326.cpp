#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cctype>
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const ll INFLL = 1001001001001001001;  // > 10^18
const int MOD = (int)1e9 + 7;
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    int n; cin >>n;
    vector<priority_queue<char, vector<char>, greater<char> > > s(n, priority_queue<char, vector<char>, greater<char> >());

    for (int i = 0; i < n; i++) {
        string this_s; cin >> this_s;
        for (int j = 0; j < this_s.length(); j++) {
            s[i].push(this_s[j]);
        }
    }

    string ans = "";
    for (char c = 'a'; c <= 'z'; c++) {
        int minc = INF;
        for (int i = 0; i < n; i++) {
            int count = 0;
            while (!s[i].empty()) {
                char t = s[i].top();
                if (t == c) {
                    s[i].pop();
                    count++;
                } else {
                    break;
                } 
            }
            minc = min(minc, count);
        }
        for (int t = 0; t < minc; t++) {
            ans += c;
        }
    }
    
    cout << ans << endl;
    return 0;
}


