#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<long> h(n);
    for(auto &x: h) cin >> x;

    long mx = -1;
    long res = 0;
    for(auto &x: h)
        if(mx <= x)
            mx = x, res++;
    cout << res << endl;
}
