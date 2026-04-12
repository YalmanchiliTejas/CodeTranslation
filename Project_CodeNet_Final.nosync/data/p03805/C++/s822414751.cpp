#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep01(i, n) for(int i = 0; i < (n) + 1; i++)
#define rep10(i, n) for(int i = 1; i < (n); i++)
#define rep11(i, n) for(int i = 1; i < (n) + 1; i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
typedef struct { int x; int y; } Pos;
using namespace std;

//*********************
//n!
//*********************

//ABC054C
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>());
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    vector<int> pattern;
    int cnt = 0;
    rep(i, N) pattern.push_back(i);
    do {
        if (pattern[0] != 0) continue;
        bool success = true;
        rep(i, N-1) {
            if (A[pattern[i]].end() == find(all(A[pattern[i]]), pattern[i + 1])) {
                success = false;
                break;
            }
        }
        if(success) cnt++;
    } while (next_permutation(all(pattern)));
    cout << cnt << endl;
    return 0;
}