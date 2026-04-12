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

    string s;
    cin >> s;

    string ans = "Yes";

    bool flagA= false,flagB = false;
    REP(i,s.size()){
        if(s[i] == 'A')flagA = true;
        else flagB = true;
    }

    if(!(flagA && flagB))ans = "No";

    cout << ans << endl;
    return 0;
}