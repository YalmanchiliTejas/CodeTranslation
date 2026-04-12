#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, G, B;
    cin >> R >> G >> B;

    int x = R*100+G*10+B;
    if(x % 4){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}