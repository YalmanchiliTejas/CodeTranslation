#include <bits/stdc++.h>

#define INF INT_MAX
#define UINF UINT_MAX
#define MOD 1000000007
#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,m;
    cin >> n >> m;

    string ans = "Yes";

    if(n != m)ans = "No"; 

    cout << ans << endl;
    return 0;
}