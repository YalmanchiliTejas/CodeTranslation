#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main() {
    int x;
    cin >> x;
    if(x==7 or x==5 or x==3){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}