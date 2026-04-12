#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int t = 100*a + 10*b + c;
    cout << (t%4 == 0 ? "YES" : "NO") << endl;
}