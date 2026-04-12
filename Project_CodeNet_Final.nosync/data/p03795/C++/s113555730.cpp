#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, y;

    y = n / 15;
    x = 800 * n;
    x -= y * 200;

    cout << x << endl;
}