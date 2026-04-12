#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    string S; cin >> S;
    int K; cin >> K;
    char target = S[K-1];
    REP(i,N) if(S[i]!=target) S[i] = '*';
    cout << S << '\n';

    return 0;
}