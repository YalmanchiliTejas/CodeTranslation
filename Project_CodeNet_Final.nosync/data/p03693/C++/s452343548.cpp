#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int l = a*100 + b * 10 + c;
    if(l % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}