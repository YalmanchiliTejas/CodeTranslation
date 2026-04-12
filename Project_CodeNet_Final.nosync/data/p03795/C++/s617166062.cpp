#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    
    int y = n / 15 * 200;
    
    cout << n * 800 - y;
}
