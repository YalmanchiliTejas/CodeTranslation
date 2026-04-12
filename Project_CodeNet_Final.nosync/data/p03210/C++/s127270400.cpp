#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(), (c).end());
const long long MOD = 1e9 + 7;
typedef long long ll;

int main(){
	int a;
	cin >> a;
	string ans = "NO";
	if(a == 3 || a == 5 || a == 7)ans = "YES";
	cout << ans << endl;
}