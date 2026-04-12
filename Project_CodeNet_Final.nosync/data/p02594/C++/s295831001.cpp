#include<iostream>
#define END "\n"
#define REP(i, a, b) for (int i = a; i < b; ++i)

using namespace std;  

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n >= 30) cout << "Yes";
    else cout << "No";
    return 0;
}
