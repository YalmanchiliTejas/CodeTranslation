#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7; //10の9乗

ll F(ll A, ll B) {
    return max(log10(A)+1, log10(B)+1);
}

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    //ソートした各要素を配列にいれる
    for(int i=0; i<n; i++) {
        string ss;
        cin >> ss;
        sort(ss.begin(), ss.end());
        S[i] = ss;
    }

    for(char c='a'; c<='z'; c++) {
        int m = count(S[0].begin(), S[0].end(), c);
        for(int j=0; j<n; j++) {
            int x = count(S[j].begin(), S[j].end(), c);
            m = min(m, x);
        }

        for(int i=0; i<m; i++) cout << c;
    }
}