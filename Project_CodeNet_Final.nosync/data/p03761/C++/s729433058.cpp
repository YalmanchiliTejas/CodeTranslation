#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n;
	string s;
	cin >> n;
	vector<int> a(26,INF);
	vector<int> b(26,0);
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < s.size(); j++) {
			b[s[j] - 'a']++;
		}
		for(int k = 0; k < 26; k++) {
			a[k] = min(a[k],b[k]);
			b[k] = 0;
		}
	}
	vector<char> ans;
	for(int i = 0; i < 26; i++) {
		while(a[i] > 0){
			ans.pb('a' + i);
			a[i]--;
		}
	}
	sort(ALL(ans));
	
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}