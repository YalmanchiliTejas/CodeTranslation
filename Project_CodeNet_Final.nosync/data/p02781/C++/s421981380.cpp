#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
#define pii pair<int , int>
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
const int INF = 1000 * 1000 * 1000 + 7;
const ll LINF = INF * (ll)INF;
int k;
string n;
ll dpT[105][4][2];
ll dp(int id , int cnt , int vpr)
{
	
	if(cnt == k)
		return 1;
	if(id == sz(n))
		return 0;
	if(dpT[id][cnt][vpr] != -1)
		return dpT[id][cnt][vpr];
	ll ans = 0;
	int bound = vpr ? (n[id] - '0') : 9;
	for(int i = 0; i <= bound; i++)
	{
		
		ans += dp(id + 1 , cnt + (i != 0) , vpr & (i == n[id] - '0'));
	}
	return dpT[id][cnt][vpr] = ans;
}
int main()
{
	memset(dpT , -1 , sizeof dpT);
	
	cin >> n >> k;
	cout << dp(0 , 0 , 1);
}
