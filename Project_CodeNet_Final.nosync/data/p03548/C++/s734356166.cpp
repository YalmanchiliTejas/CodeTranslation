#include<iostream>

using namespace std;

typedef long long int ll;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y , z;
    cin >> x >> y >> z;
    x = x- z;
    int n = (x)/(y+z);
    cout << n << endl;
}
