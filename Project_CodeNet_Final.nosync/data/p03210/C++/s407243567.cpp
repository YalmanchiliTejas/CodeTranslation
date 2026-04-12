#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);

    int x; 
    cin >> x; 

    bool yes = (x == 5 or x == 7 or x == 3); 
    yes ? cout << "YES\n" : cout << "NO\n";
}