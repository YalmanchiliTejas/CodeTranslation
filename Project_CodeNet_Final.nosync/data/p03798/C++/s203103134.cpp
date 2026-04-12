#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
#define LINF (long long)4e18

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;







int main(){
	int N; cin >> N;
	string s; cin >> s;
	vector<int> which(N);
	vector<int> a{1,-1,1,-1};
	vector<int> b{1,1,-1,-1};
	bool isok = false;
	rep(i,4){
		which[0] = a[i];
		which[1] = b[i];
		bool ok = true;
		repr(j,1,N-1){
			if(s[j] == 'o' && which[j] == 1){
				which[j+1] = which[j-1];
			}
			if(s[j] == 'o' && which[j] == -1){
				which[j+1] = -which[j-1];
			}
			if(s[j] == 'x' && which[j] == 1){
				which[j+1] = -which[j-1];
			}
			if(s[j] == 'x' && which[j] == -1){
				which[j+1] = which[j-1];
			}
		}
		if(which[0] == 1 && s[0] == 'o'){
			if(which[1] != which[N-1]) ok = false;
		}
		if(which[0] == 1 && s[0] == 'x'){
			if(which[1] != -which[N-1]) ok = false;
		}
		if(which[0] == -1 && s[0] == 'o'){
			if(which[1] != -which[N-1]) ok = false;
		}
		if(which[0] == -1 && s[0] == 'x'){
			if(which[1] != which[N-1]) ok = false;
		}
		if(which[N-1] == 1 && s[N-1] == 'o'){
			if(which[N-2] != which[0]) ok = false;
		}
		if(which[N-1] == 1 && s[N-1] == 'x'){
			if(which[N-2] != -which[0]) ok = false;
		}
		if(which[N-1] == -1 && s[N-1] == 'o'){
			if(which[N-2] != -which[0]) ok = false;
		}
		if(which[N-1] == -1 && s[N-1] == 'x'){
			if(which[N-2] != which[0]) ok = false;
		}

		if(ok){
			isok = true;
			break;
		}

	}
	if(!isok) cout << -1 << endl;
	else{
		vector<char> ans(N);
		rep(i,N){
			if(which[i] == 1) ans[i] = 'S';
			else ans[i] = 'W';
			cout << ans[i];
		}
		cout << endl;
	}
	
}
