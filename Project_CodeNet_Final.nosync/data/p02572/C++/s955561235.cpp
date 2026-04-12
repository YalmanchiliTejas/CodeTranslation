#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(n) (n).begin(),(n).end()
#define fi first
#define se second

typedef pair<int, int> PII;
typedef long long ll;

const int MOD = 1e9+7;

ll s[200005],o[200005],n;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;
	for (int i=0;i<n;i++) cin>>s[i],o[i]=s[i];
	for (int i=1;i<n;++i) s[i]+=s[i-1],s[i]%=MOD;
	ll tot = s[0]*((s[n-1]-s[0]+MOD)%MOD);
	for (int i=1;i<n;++i) {
		tot+=(o[i])*((s[n-1]-s[i]+MOD)%MOD);
		tot%=MOD;
	}
	cout << tot << "\n";
}