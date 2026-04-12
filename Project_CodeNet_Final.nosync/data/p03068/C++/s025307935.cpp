#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;


int main() {
    int N, K; string S; cin >> N >> S >> K;
    char ch = S[K-1];
    for(int i = 0; i < N; i++) if(S[i] != ch) S[i] = '*';
    cout << S << endl;


}