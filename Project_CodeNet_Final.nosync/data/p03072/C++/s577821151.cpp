#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define print(n) std::cout << n << std::endl
using namespace std;


int main() {
    int n; cin >> n;

    vector<int> h(n);

    rep(i,n)cin >> h[i];

    int count = 0;
    int higtest = h[0];

    for (int i = 0; i < n; ++i) {
        if(h[i] >= higtest){
                higtest = h[i];
                count++;
            }
        }
    print(count);
}