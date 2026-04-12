#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

typedef long long ll;
typedef ll li;
typedef pair<int,int> PI;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,m,n) for(int i=m; i<=(int)(n); ++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(),a.end()
#define FOR(it,a) for(__typeof(a.begin())it=a.begin();it!=a.end();++it)
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,-1,1,1,-1};


int n,m;
set<vector<string> > app,dir;

vector<string> parse(string in){

  FOR(it,in) if(*it=='/') *it = ' ';  
  stringstream ss(in);
  vector<string> path;
  vector<string> raise;
  raise.pb("$");
  
  while(ss >> in){
    if(in==".") {
      if(app.count(path))
        return raise;
      continue;
    }
    
    if(in==".."){
      if(app.count(path))
        return raise;
      
      if(!path.empty()){
        path.pop_back();
        continue;
      }
      
      return raise;
    }
    
    if(!dir.count(path))
      return raise;
    path.pb(in);
    if(!dir.count(path) &&
       !app.count(path))
      return raise;
  }
  
  return path;
}

void solve(){
  app.clear();
  dir.clear();
  
  rep(i,n){
    string in;
    cin >> in;
    FOR(it,in) if(*it=='/') *it = ' ';
    
    stringstream ss(in);
    vector<string> path;
    while(ss >> in){
      dir.insert(path);
      path.pb(in);
    }
    app.insert(path);
  }

  rep(i,m){
    string a,b;
    cin >> a >> b;
    bool indea=false,indeb=false;
    if(a[SZ(a)-1]=='/'){
      indea=true;
      a=a.substr(0,SZ(a)-1);
    }
    if(b[SZ(b)-1]=='/'){
      indeb=true;
      b=b.substr(0,SZ(b)-1);
    }    
    vector<string> pa,pb;
    pa=parse(a);
    pb=parse(b);
    if(0){
    FOR(it,pa) cout << *it << ' ';
    cout << endl;
    FOR(it,pb) cout << *it << ' ';
    cout << endl;
    cout << endl;
    }
    
    if(dir.count(pa) || indea) pa.pb("index.html");
    if(dir.count(pb) || indeb) pb.pb("index.html");
    
    if(pa==pb && app.count(pa)) cout << "yes" << endl;
    else if(app.count(pa)+app.count(pb)<2) cout << "not found" << endl;
    else cout << "no" << endl;
  }
}

main(){
  while(cin >> n >> m,n)
    solve();
}