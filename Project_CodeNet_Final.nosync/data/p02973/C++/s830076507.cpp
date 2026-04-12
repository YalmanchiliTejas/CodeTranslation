#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(S) (S).begin(), (S).end()
#define pf push_front
#define pb push_back
#define mk make_pair
#define S second
#define F first
typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
const int MAX = 1e5+5;
map<int, int> mp;
int N, ans, x;
set<int> st;

int main(int argc, char ** argv) {
	set<int> :: iterator it;
	scanf("%d", &N);
	rep(i, 0, N) { 
		scanf("%d", &x); x = -x;
		it = st.upper_bound(x);
		if(it != st.end()) {
			mp[*it]--;
			if(!mp[*it]) st.erase(it);
		}
		st.insert(x);
		mp[x]++;
	}
	for(it = st.begin(); it != st.end(); it++)
		ans += mp[*it];
	printf("%d\n", ans);
	return 0;
}
