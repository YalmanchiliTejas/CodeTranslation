#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "../.inc/debug.hpp"
#else
#define debug(...) 42
#define rdfile(...) 42
#endif

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // rdfile("_input.txt");

    int n;
    cin >> n;

    vector<int> lis(n, -1);
    int a;
    for (int i=0; i<n ; ++i) {
        cin >> a;
        int k = lower_bound(lis.begin(), lis.end(), a) - lis.begin();
        lis[k-1] = a;
    }

    int col = 0;
    for (int i=n-1; i>=0; --i) {
        if (lis[i] != -1) {
            col ++;
            continue;
        }
        break;
    }
    cout << col << endl;

    return 0;
}