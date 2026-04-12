#include <bits/stdc++.h>
#include <unordered_map>
#define mem(ara, a) memset(ara, a, sizeof(ara))
#define fo freopen("output.txt", "w", stdout)
#define fi freopen("bruh.txt", "r", stdin)
#define int long long
#define sp " "
#define pb push_back
#define ff first
#define sz(x) x.size();
#define len(x) x.length();
#define ss second
#define vi vector<int>
#define double long double
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pii pair<int, int>


long long inf = 2e18;
long long minf = -inf;
int ans = 0;
using namespace std;

signed main() {
set<char >SET;
for (int i=0;i<3;i++){
char ch;
cin >> ch;
SET.insert(ch);
}
if (SET.size()==2){
    cout << "Yes" << endl;
}
else {
    cout << "No" << endl;
}

}
