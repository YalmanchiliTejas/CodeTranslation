#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
const double eps = 1e-8;
const double pi = acos(-1.0);
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
string s;
bool ok1,ok2;
int main(){
	cin >> s;
	for(int i = 0;i < 3;i++){
		if(s[i] == 'A') ok1 = 1;
		if(s[i] == 'B') ok2 = 1;
	}
	if(ok1&&ok2) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}