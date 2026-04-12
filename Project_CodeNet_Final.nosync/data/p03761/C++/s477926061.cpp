#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    string X;

    for(int i=0; i<N; i++) {
        cin >> S[i];
    }

    for(char c = 'a'; c <= 'z'; c++) {
        int n = count(S[0].begin(),S[0].end(), c);
        for(int i=1; i<N; i++) {
            int x = count(S[i].begin(), S[i].end(), c);
            if (x < n) n = x;
        }
        for(int i=0; i<n; i++) X.push_back(c);
    }
    cout << X << endl;
}