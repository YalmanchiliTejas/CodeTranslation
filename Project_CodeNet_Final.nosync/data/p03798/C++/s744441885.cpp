#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

void solve(string& t, string s){
	int N = (int)s.length();
	for (int j = 1; j < N - 2; ++j){
		if (t[j] == 'S'){
			if (s[j] == 'o'){
				t[j+1] = t[j-1];
			}else{ // if (s[j] == 'x')
				t[j+1] = (t[j-1] == 'S' ? 'W' : 'S');
			} // end if
		}else{ // if (t[j] == 'W')
			if (s[j] == 'o'){
				t[j+1] = (t[j-1] == 'S' ? 'W' : 'S');
			}else{ // if (s[j] == 'x')
				t[j+1] = t[j-1];
			} // end if
		} // end if
	} // end for
}

bool check(string t, string s){
	int N = (int)t.length();
	rep (i, N){
		if (s[i] == 'o'){
			if (t[i] == 'S'){
				if (t[(N-1+i)%N] != t[(i+1)%N]) return false;
			}else{ // if (t[i] == 'W')
				if (t[(N-1+i)%N] == t[(i+1)%N]) return false;
			} // end if
		}else{ // if (s[i] == 'x'){
			if (t[i] == 'S'){
				if (t[(N-1+i)%N] == t[(i+1)%N]) return false;
			}else{ // if (t[i] == 'W')
				if (t[(N-1+i)%N] != t[(i+1)%N]) return false;
			} // end if
		} // end if
	} // end rep
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	string s; cin >> s;
/*
	assert(N < 20);

	rep (i, 1<<N){
		string t = "";
		rep (j, N){
			if (i & (1<<j)){
				t += 'S';
			}else{
				t += 'W';
			} // end if
		} // end rep
		string u = "";
		rep (j, N){
			if (t[(N + j - 1) % N] == t[(j + 1) % N]){
				u += (t[j] == 'S' ? 'o' : 'x');
			}else{
				u += (t[j] == 'S' ? 'x' : 'o');
			} // end if
		} // end rep
		if (s == u){
			cout << t << endl;
			return 0;
		} // end if
	} // end rep
*/
	string res = "";
	rep (i, (1<<3)){
		string t(N, '.');
		rep (j, 3){
			if (i & (1<<j)){
				t[(N - 1 + j) % N] = 'S';
			}else{
				t[(N - 1 + j) % N] = 'W';
			} // end if
		} // end rep
		if (s[0] == 'o'){
			if (t[0] == 'S'){
				if (t[N-1] != t[1]) continue;
			}else{ // if (t[0] == 'W')
				if (t[N-1] == t[1]) continue;
			} // end if
			solve(t,s);
			if (t[N-2] == 'S'){
				if (s[N-2] == 'o'){
					if (t[N-3] != t[N-1]) continue;
				}else{ // if (s[N-1] == 'x')
					if (t[N-3] == t[N-1]) continue;
				} // end if
			}else{ // if (t[N-1] == 'W')
				if (s[N-2] == 'o'){
					if (t[N-3] == t[N-1]) continue;
				}else{ // if (s[N-1] == 'x')
					if (t[N-3] != t[N-1]) continue;
				} // end if
			} // end if
			res = t;
		}else{ // if (s[0] == 'x')
			if (t[0] == 'S'){
				if (t[N-1] == t[1]) continue;
			}else{ // if (t[0] == 'W')
				if (t[N-1] != t[1]) continue;
			} // end if
			solve(t,s);
			if (t[N-2] == 'S'){
				if (s[N-2] == 'o'){
					if (t[N-3] != t[N-1]) continue;
				}else{ // if (s[N-1] == 'x')
					if (t[N-3] == t[N-1]) continue;
				} // end if
			}else{ // if (t[N-1] == 'W')
				if (s[N-2] == 'o'){
					if (t[N-3] == t[N-1]) continue;
				}else{ // if (s[N-1] == 'x')
					if (t[N-3] != t[N-1]) continue;
				} // end if
			} // end if
			res = t;
		} // end if
		if (!res.empty()){
			if (!check(res, s)){
				res = "";
				continue;
			}else{
				break;
			} // end if
		} // end if
	} // end rep

	cout << (res.empty() ? "-1" : res) << endl;

	return 0;
}