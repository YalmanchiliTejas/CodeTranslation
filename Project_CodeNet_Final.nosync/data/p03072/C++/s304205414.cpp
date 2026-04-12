#include <bits/stdc++.h>
using namespace std;
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20);} } fast;

int main() {
    int n, s = 0, h, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> h;
        if (s <= h){
            s = h;
            c++;
        }
    }
    cout << c << endl;
}