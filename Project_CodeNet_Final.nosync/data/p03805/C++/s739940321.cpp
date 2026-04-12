#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
set<pii> Edges;

int main()
{
    int N, M;
    cin >> N >> M;
    for (int m = 0; m < M; ++m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        Edges.insert(make_pair(a, b));
        Edges.insert(make_pair(b, a));
    }

    vector<int> Now;
    for (int n = 0; n < N; ++n) {
        Now.push_back(n);
    }

    int Res = 0;
    do {
        if (Now[0] != 0) break;
        bool OK = true;
        for (int n = 0; n < N-1; ++n) {
            if (Edges.count(make_pair(Now[n], Now[n+1])) == 0) {
                OK = false;
                break;
            }
        }
        if (OK) ++Res;
    } while (next_permutation(Now.begin(), Now.end()));

    cout << Res << endl; 
}