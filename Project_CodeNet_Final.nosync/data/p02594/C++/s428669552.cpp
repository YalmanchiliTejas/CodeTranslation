#include <bits/stdc++.h>
#define debug1(x) cout << #x << " " << x << endl;
#define debug2(x,y) cout << #x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout << #x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
using namespace std;

void readFile() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

ll binpow(ll a,ll b) {    // a^b
    if(b==0) return 1;
    long long res = binpow(a,b/2);
    if(b%2)
        return res*res*a;
    else
        return res*res;
}

int main() {
    readFile();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    if(T>=30)
    cout << "Yes\n";
else cout << "No\n";
    return 0;
}
