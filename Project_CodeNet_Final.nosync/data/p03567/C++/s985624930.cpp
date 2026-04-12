/*#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
*/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f;
const ll nax = 0;
string s;
unordered_map<char, int>cnt;

int main(){
	IOS
	cin >> s;
	for(int i=0;i<s.length();++i){
		if(s[i]=='A' && s[i+1]=='C'){
			cout << "Yes" << '\n';
			return 0;
		}
	}
	cout << "No" << '\n';
}
