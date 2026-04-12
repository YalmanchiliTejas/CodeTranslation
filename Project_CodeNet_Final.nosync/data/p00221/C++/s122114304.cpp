#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) (v).begin(), (v).end()
#define rev(s) (s).rbegin(), (s).rend()
#define MP make_pair
#define X first
#define Y second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;

bool check(string s, int cnt){
	if(cnt%15 == 0) return s == "FizzBuzz";
	if(cnt%5 == 0) return s == "Buzz";
	if(cnt%3 == 0) return s == "Fizz";
	rep(i, s.size()){
		if(s[i] < '0' || s[i] > '9') return false;
	}
	return atoi(s.c_str()) == cnt;
}

int main(){
	int m, n;
	while(cin >> m >> n, m|n){
		vector<int> player(m);
		rep(i, m) player[i] = i;

		int p = 0;
		FOR(i, 1, n+1){
			string s;
			cin >> s;
			if(player.size()==1) continue;

			if(!check(s, i)) player.erase(player.begin()+p);
			else p++;
			p%=player.size();
		}
		rep(i, player.size()){
			cout << (i?" ":"") << player[i]+1;
		}
		cout << endl;
	}

	return 0;
}