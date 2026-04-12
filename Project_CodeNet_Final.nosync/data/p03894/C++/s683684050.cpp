#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, Q; cin >> N >> Q;
    int curr = 0;
    vector<bool> poss(N);
    poss[0] = poss[1] = true;
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b; a--, b--;
        swap(poss[a], poss[b]);
        if (curr == a) curr = b;
        else if (curr == b) curr = a;
        if (curr+1 < N) poss[curr+1] = true;
        if (curr-1 >= 0) poss[curr-1] = true;
    }
    cout << accumulate(begin(poss), end(poss), 0) << endl;
    return 0;
}