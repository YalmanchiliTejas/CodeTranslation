#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define ct(string) cout << string << endl

int main() {
    int n, ans=0, ma=0;
    cin >> n;
    rep(i,n) {
        int c;
        cin >> c;
        if (c >= ma) ans++;
        ma = max(ma, c);
    }
    ct(ans);
}