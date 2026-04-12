#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 7 || N == 5 || N == 3) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
