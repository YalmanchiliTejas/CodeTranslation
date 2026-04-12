#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int num = r * 100 + g * 10 + b;
    if ( num % 4 == 0 ) cout << "YES" << endl;
    else                cout << "NO" << endl;
    return 0;
}
