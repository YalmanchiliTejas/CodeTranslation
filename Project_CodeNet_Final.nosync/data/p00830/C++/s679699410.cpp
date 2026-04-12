#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n, m;
bool ok(string &s, const set<string> &d, const set<string> &f){
	string t = s;
	bool flag = 0;
	if(t[t.size() - 1] == '/') t += "index.html", flag = 1;
	
	each(i, t) if(*i == '/') *i = ' ';
	stringstream ss(t);
	s = "";
	while(ss >> t){
		//dbg(s);
		if(!d.count(s)) return 0;
		if(t == ".") continue;
		if(t == ".."){
			int p = s.rfind("/");
			if(p != s.npos) s = s.substr(0, p);
		}
		else{
			s += "/" + t;
		}
	}
	if(!flag && !f.count(s)) s += "/index.html";
	return f.count(s);
}
int main(){
	while(cin >> n >> m, n){
		set<string> dir, file;
		string s, t;
		
		rep(i, n){
			cin >> s;
			file.insert(s);
			int p;
			while((p = s.rfind("/")) != s.npos){
				s = s.substr(0, p);
				dir.insert(s);
			}
		}
		rep(i, m){
			cin >> s >> t;
			if(!ok(s, dir, file) || !ok(t, dir, file)) cout << "not found" << endl;
			else cout << (s == t ? "yes" : "no") << endl;
		}
	}
	return 0;
}