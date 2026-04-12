#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500];
int main() {
    //freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    for (int i = 0; i+1 < s.size(); i++)
        if (s.substr(i,2) == "AC") {
            cout << "Yes" << endl;
            return 0;
        }
    cout << "No" << endl;

    return 0;
}
