#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define INF (1<<29)
#define EPS 1e-10
#define MOD 1000000007

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

struct node{
  string name;
  int ide;
  struct node *par;
  struct vector<node*>child; 
};
node root;

vector<string> split(string s, char c)
{
  vector<string>ret;
  int i=0;
  for(;i<s.size();i++){
    for(int j=i;j<s.size();j++){
      if(s[j] == c){
	if(i!=j){
	  ret.push_back(s.substr(i,j-i));
	  i = j;
	}
	break;
      }
      if(j == s.size()-1){
	ret.push_back(s.substr(i));
	i = j;
      }
    }
  }
  return ret;
}

string default_file = "index.html";
string par_dir = "..";
string cur_dir = ".";
string root_dir = "/";


int dfs(node n)
{
  cout << n.ide<<" "<< n.name << " "<< n.child.size() << endl;
  for(auto c: n.child)
    dfs(*c);
}

int search(string s)
{

  vector<string>V = split(s, '/');
  node *n = &root;
  if(s.size() == 1){
    for(auto c: n->child)
      if(c->name == default_file && c->child.size() == 0)
	return c->ide;
    return -1;
  }
  for(auto v: V){
    if(n->child.size() == 0) return -1;
    //    cout << n->name << endl;
    if(v == par_dir){
      //      cout << n->par << endl;
      if(n->par != (node*)-1) n = n->par;
      else return -1;
      continue;
      //      cout << n->name << endl;      
    }
    if(v == cur_dir) continue;
    int flag = 0;
    for(auto c: n->child){
      //      cout << c->name << " " << v << endl;
      if(c->name == v){
	flag = 1;
	n = c;
	break;
      }
    }
    if(!flag) return -1;
  }
  if(s[s.size()-1] == '/' && n->child.size() == 0) return -1;
  if(n->child.size()){
    int flag= 0;
    for(auto c: n->child)
      if(c->name == default_file){
	n = c;
	flag = 1;
	break;
      }
    if(!flag) return -1;
  }
  
  return n->ide;
}

int main()
{
  int N, M;
  while(1){
    cin >> N >> M;
    if(N == 0 && M == 0) return 0;
    int idecnt = 0;

    root.ide = idecnt;
    root.par = (node*)-1;
    root.name = "/";
    root.child.clear();

    rep(i, N){
      string s; cin >> s;
      vector<string>V = split(s, '/');
      //    for(auto v: V) cout << v << endl;
      node *n = &root;
      for(auto v: V){
	//      cout << v << endl;
	int flag = 0;
	rep(i, n->child.size()){
	  if(n->child[i]->name == v){
	    //	  cout << "exsit "<< n->child[i]->name << endl;	  
	    n = n->child[i];
	    flag = 1;
	    break;
	  }
	}
	if(!flag){
	  node *nn = new node;
	  //	cout << "create " << v << endl;				
	  nn->name = v;
	  nn->par = n;
	  nn->ide = ++idecnt;
	  n->child.push_back(nn);
	  n = nn;
	}
      }
    }
    //  dfs(root);  

    rep(i, M){
      string s; cin >> s;
      int id1 = search(s);
      cin >> s;
      int id2 = search(s);
      //    cout << id1 << " " << id2 << endl;
      if(id1 == -1 || id2 == -1) cout << "not found\n";
      else if(id1 == id2) cout << "yes\n";
      else cout << "no\n";
      
    }
  }
  return 0;
}