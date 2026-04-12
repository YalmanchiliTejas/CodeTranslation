#include <bits/stdc++.h>
using namespace std;

int main(){
int X, Y, Z; cin >> X >> Y >> Z;

int ans = 0;
int room = X - Z;
while (room >= 0) {
    if (room >= Y + Z) {
        ans++;
    }
    room -= Y + Z;
}

cout << ans << endl;

}
