#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define rep(i, s, n) for(int i = s;i<n;i++)

int main(void) {
    int x;
    cin >> x;
    if (x == 7 || x == 5 || x == 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}