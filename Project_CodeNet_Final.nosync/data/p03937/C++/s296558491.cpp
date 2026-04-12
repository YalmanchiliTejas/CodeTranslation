#include <iostream>
using namespace std;
typedef long long ll;
ll h, w, ans;
string str[10];
int main(void){
    // Your code here!
    cin >> h >> w;
    for (ll i = 0; i < h; i++) {
        cin >> str[i];
    }
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            if (str[i][j] == '#') ans++;
        }
    }
    if (ans == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
