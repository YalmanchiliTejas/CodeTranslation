#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ll n, arr[55][55];
unordered_map<ll, ll>cnt;
	
int main(void){
	IOS
	memset(arr, 0, sizeof arr);
	cin >> n;
	vector<string>s(n);
	for(int i=0;i<n;i++){
		cin >> s[i];
		ll sais=s[i].size();
		for(int j=0;j<sais;j++){
			ll c=s[i][j]-'a';
			arr[i][c]++;
		}
	}
	for(int i=0;i<26;i++) cnt[i]=inf;
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++){
			cnt[j]=min(cnt[j], arr[i][j]);
		}
	}
	for(int i=0;i<26;i++){
		int ukuran=cnt[i];
		while(ukuran--){
			char k=i+'a';
			cout << k;
		}
	}
	cout << '\n';
}
