#include <iostream> // import 標準入出力
using namespace std; // as *
int main() {
    int r, g, b;
    cin >> r >> g >>  b; // cin: キーボード入力
    int c = r *100 +  g * 10 + b;
    if (c % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
