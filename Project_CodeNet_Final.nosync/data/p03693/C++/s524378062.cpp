#include <bits/stdc++.h>
#include <string.h>
#define rep(i, n) for(int i = 0; i<(n); i++)
using namespace std;
typedef long long ll;

int main() {

    int r, g, b;
    cin >> r >> g >> b;
    if((100 * r + 10 * g + b) % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}
