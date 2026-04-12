#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int x;
  	cin >> x;
  	if (x >= 30) {
    	cout << "Yes" << endl;
    } else {
    	cout << "No" << endl;
    }
    return 0;
}
