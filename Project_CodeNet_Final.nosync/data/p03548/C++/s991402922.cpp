#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int X, Y, Z;
    cin >> X >> Y >> Z;

    X -= Z;

    cout << X / (Y + Z) << endl;
}