#include <bits/stdc++.h>
using namespace std;
int main() {
    #ifdef DEBUG
    std::ifstream in("/home/share/inputf.in");
    std::cin.rdbuf(in.rdbuf());
    #endif
    int N;
    cin >> N;
    int M = 0, ans = 0;
    for(int i = 0; i < N; i++) {
        int H;
        cin >> H;
        if(M <= H) ans++;
        M = max(M, H);
    }
    cout << ans << endl;
    return 0;
}