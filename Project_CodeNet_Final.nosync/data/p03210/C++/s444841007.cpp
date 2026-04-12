#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int X;
    cin >> X;
    if (X == 7 || X == 5 || X == 3)
        cout << "YES"<< endl;
    else
        cout << "NO" << endl;
    return 0;
}


