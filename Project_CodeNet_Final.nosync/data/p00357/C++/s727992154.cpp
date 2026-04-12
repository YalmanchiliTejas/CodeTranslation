#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int D[300005];
    bool flag = false;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> D[i];
    }

    int maxv = 0;
    for(int i = 0; i < N; i++) {
        if(maxv < 0) {
            flag = true;
        }
        maxv = max(D[i], maxv);
        maxv -= 10;
    }
    maxv = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(maxv < 0) {
            flag = true;
        }
        maxv = max(D[i], maxv);
        maxv -= 10;
    }
    if(flag) cout << "no" << endl;
    else cout << "yes" << endl;
    return (0);
}