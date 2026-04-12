#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define ford(i, n) for (int i = int(n)-1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define ms(a, x) memset(a, x, sizeof(a))
#define F first
#define S second
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define de(x) cout<<#x<<" = "<<(x)<<endl
#define de2(x,y) cout<<#x<<" = "<<(x) <<' '<< #y<<" = "<<y<<endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
ll nxt(){ll x;cin>>x;return x;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	string st;
    cin>>st;
    if(st!="AAA"&&st!="BBB") cout<<"Yes";
    else cout<<"No";
    return 0;
}

