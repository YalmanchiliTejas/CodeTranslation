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

char copy(const char c){return c;}

int main(){
	int n;cin>>n;
	string s;cin>>s;
	int k;cin>>k;
	k--;
	char x = copy(s[k]);
	for(int i = 0; i < s.size(); i++) {
		if (s[i] != x)s[i] = '*';
	}
	cout << s << endl;
	return 0;
}