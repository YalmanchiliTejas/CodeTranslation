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

map<string, int> mp;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    cout << x / (y + z) << endl;
    return 0;
}