#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string st;
typedef double db;
typedef vector<long long> vecll;
typedef vector<char> vechar;

int main(){
    ll r, g, b;
    cin >> r >> g >> b;
    ll card = 100 * r + 10 * g + b;
    if(card % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}