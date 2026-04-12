#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

char rev(char c){
	return (c == 'S' ? 'W' : 'S');
}

int N;
string s,t;

bool check(string str){
	bool ok = true;
	rep (i, N){
		char cl = str[(N-1+i)%N];
		char cr = str[(i+1)%N];
		if (s[i] == 'o'){
			if (str[i] == 'S'){
				ok &= (cl == cr);
			}else{ // if (str[i] == 'W')
				ok &= (cl != cr);
			} // end if
		}else{ // if (s[i] == 'x')
			if (str[i] == 'S'){
				ok &= (cl != cr);
			}else{ // if (str[i] == 'W')
				ok &= (cl == cr);
			} // end if
		} // end if
	} // end rep
	return ok;
}

bool process(string str){
	t = str;
	t.resize(N);
	for (int i = 1; i < N - 1; ++i){
		if (t[i] == 'S'){
			if (s[i] == 'o'){
				t[i+1] = t[i-1];
			}else{ // if (s[i] == 'x')
				t[i+1] = rev(t[i-1]);
			} // end if
		}else{ // if (t[i] == 'W')
			if (s[i] == 'o'){
				t[i+1] = rev(t[i-1]);
			}else{ // if (s[i] == 'x')
				t[i+1] = t[i-1];
			} // end if
		} // end if
	} // end for
	return check(t);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cin >> s;
	
	bool ok = false;
	rep (i,1<<2){
		string str = "";
		rep (j, 2){
			if (i & (1<<j)){
				str += 'S';
			}else{
				str += 'W';
			} // end if
		} // end rep
		ok = process(str);
		if (ok){
			cout << t << endl;
			return 0;
		} // end if
	} // end rep
	cout << -1 << endl;

	return 0;
}