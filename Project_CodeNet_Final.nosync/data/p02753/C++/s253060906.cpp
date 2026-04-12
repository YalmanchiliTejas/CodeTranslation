#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
	string s;cin >> s;
	if(s[0]==s[1]&&s[1]==s[2]){
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
  return 0;
}
