#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(a) begin(a), end(a)
#define deb(x) cout << #x << " = " << x << endl
template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

void yes() {cout << "YES" << "\n";}
void no() {cout << "NO" << "\n";}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x;
  	cin >> x;
  	if(x >= 30) {
      cout << "Yes" << endl;
    } else cout << "No" << endl;
    return 0;
}
