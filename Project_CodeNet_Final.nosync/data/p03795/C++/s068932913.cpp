#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,y,N,a,b;
    cin >> N;

    a = N / 15;
    x = 800 * N;
    y = 200 * a;

    b = x - y;

    cout << b << endl;
}