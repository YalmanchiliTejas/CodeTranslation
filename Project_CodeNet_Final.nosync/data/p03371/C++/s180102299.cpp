#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using P = pair<int, int>;

int main(){
	int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int o1,o2,o3,o4;
    int both = min(x,y);
    o1 = a*x + b*y;
    o2 = 2*c*both + (x-both)*a + (y-both)*b;
    o3 = 2*c*x + b*max(y-x, 0);
    o4 = 2*c*y + a*max(x-y, 0);

    int out = min({o1,o2,o3,o4});

    cout << out << endl;

	return 0;
}