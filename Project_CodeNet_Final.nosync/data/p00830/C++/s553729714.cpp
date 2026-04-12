//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

struct Tree{
  string name;
  Tree* par;
  vector<Tree> chd;

  Tree* found(string s){
	REP(i,SZ(chd))
	  if(chd[i].name == s)
		return &chd[i];
	return 0;
  }
  Tree(): par(0){}
};

void dfsp(Tree& t, int d){
  REP(i,d) cout << " ";
  cout << t.name << endl;
  for(auto& ch: t.chd)
	dfsp(ch, d+1);
}

VS part(string s){
  VS res;
  int p = 0;
  for(int j=0;j<SZ(s);++j){
	if(s[j] == '/' || j == SZ(s)-1){
	  string t = s.substr(p, j-p+1);
	  res.PB(t);
	  p = j + 1;
	}
  }

  return res;
}


Tree* dir(VS& path, Tree* cur){
  REP(j,SZ(path)){
	if(path[j] == "." || path[j] == "./") continue;
	else if(path[j] == ".." || path[j] == "../"){
	  cur = cur->par;
	  if(!cur) return 0;
	}
	else{
	  Tree* nxt = cur->found(path[j]);
	  if(nxt)
		cur = nxt;
	  else if(path[j].back() != '/')
		cur = cur->found(path[j]+"/");
	  else
		cur = 0;
	  if(!cur) return 0;
	}
  }

  if(cur->name.back() == '/'){
	//	for(auto& s: path) cout << s << "->";cout<<endl;
	cur = cur->found("index.html");
  }
  return cur;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  while(cin>>N>>M,N){
	Tree root;
	root.chd.emplace_back();
	root.chd.back().name = "/";
	REP(i,N){
	  Tree* cur = &root;
	  string s; cin >> s;
	  // /?????¨?????????
	  VS p = part(s);

	  for(int j=0;j<SZ(p);++j){
		string& t = p[j];
		Tree* nxt = cur->found(t);
		// ?????£??¬?????????????????¨???????????¨???
		if(!nxt){
		  cur->chd.emplace_back();
		  cur->chd[SZ(cur->chd)-1].par = cur;
		  cur = &cur->chd[SZ(cur->chd)-1];
		  cur->name = t;
		}
		else cur = nxt;
	  }
	}
	
	REP(i,M){
	  string d1, d2; cin >> d1 >> d2;
	  VS p1 = part(d1), p2 = part(d2);
	  Tree* t1 = dir(p1, &root);
	  Tree* t2 = dir(p2, &root);

	  if(!t1 || !t2) cout << "not found" << endl;
	  else if(t1 != t2) cout << "no" << endl;
	  else cout << "yes" << endl;
	}
  }

  return 0;
}