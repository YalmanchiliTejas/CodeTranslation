#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    while (cin >> n >> a >> b) {
        cout << (n - b) / (a + b) << endl;
    }
    return 0;
}
