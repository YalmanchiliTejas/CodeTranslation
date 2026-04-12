#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll inf = 1e6+5;
typedef pair<int, bool> pib;

int main() {
    int a,b,c; cin >> a >> b >> c;
    if (((a*100) + (b*10) + c) %4 == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

