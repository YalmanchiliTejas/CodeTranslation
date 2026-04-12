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
    int n, k;
    string s;
    cin >> n >> s >> k;
    rep(i, n) {
        if ( s[i] == s[k-1] ) cout << s[i];
        else                  cout << '*';
    }
    cout << endl;
    return 0;
}
