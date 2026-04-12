#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<int> cnt(26, 100);
    string S;
    for (int i = 0; i < N; i++) {
        vector<int> tmp(26, 0);
        cin >> S;
        for (int i = 0; i < S.size(); i++) tmp[S[i] - 'a']++;
        for (int i = 0; i < 26; i++) cnt[i] = min(cnt[i], tmp[i]);
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            for (int j = 0; j < cnt[i]; j++) cout << char(i + 'a');
        }
    }
    cout << endl;
    return 0;
}
