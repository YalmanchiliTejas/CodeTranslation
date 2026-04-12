#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
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
typedef vector<int> vi;

struct team{
	string name;
	int score;
	int num;
	team(string n, int s, int nu):name(n), score(s), num(nu){}
	bool operator<(const team &r)const{
		if(score == r.score) return num > r.num;
		return score < r.score;
	}
};

int main(){
	int n;
	int dataset = 0;
	while(cin >> n, n){
		if(dataset++)cout << endl;
		vector<team> v;
		rep(i, n){
			string name;
			int w, l, d;
			cin >> name >> w >> l >> d;
			v.push_back(team(name, w*3+d, i));
		}
		sort(rev(v));
		rep(i, n){
			cout << v[i].name << ',' << v[i].score << endl; 
		}
	}

	return 0;
}