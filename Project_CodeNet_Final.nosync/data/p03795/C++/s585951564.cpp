#include<bits/stdc++.h>
using namespace std;

int main () {
    static int N;
    cin >> N;
    static int x, y;
    x = 800*N;
    y = 200*(N/15);
    cout << x-y << endl;
}
