#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    cout << x / (y+z) << endl;
    return 0;
}


