#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF 1000000000
#define mod 1000000007


int main() {
    int N; cin >> N;
    vector<vector<int>> table(N, vector<int>(26));
    vector<string> S(N);
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<s.size(); j++){
            table[i][s[j]-'a']++;
        }
    }

    string hibari = "";
    for(int i=0; i<26; i++){
        int cnt = 2500;
        for(int j=0; j<N; j++)
            cnt = min(cnt, table[j][i]);
        for(int j=0; j<cnt; j++)
            hibari += char('a' + i);
    }

    cout << hibari << endl;
    return 0;
}
