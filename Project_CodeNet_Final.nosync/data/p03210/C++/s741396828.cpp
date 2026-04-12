#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
#include<map>
#include<set>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef string s;
typedef int i;

map<string, int> mp;

int main() {
    i x;
    cin >> x;
    if (x == 3 || x == 5 || x == 7) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}