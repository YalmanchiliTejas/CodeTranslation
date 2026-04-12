#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct link_dat{
  link_dat(){}
  link_dat(int l, int u, int r, int d, const string &p)
    :l(l), u(u), r(r), d(d), p(p) {}

  bool in(int x, int y){
    return (x>=l && x<=r && y>=u && y<=d);
  }

  int l, u, r, d;
  string p;
};

int main()
{
  for (int n; cin>>n, !(n==0); ){
    int w, h; cin>>w>>h;
    map<string, vector<link_dat> > page;
    string home;
    for (int i=0; i<n; i++){
      string name; cin>>name;
      int m; cin>>m;
      if (i==0) home=name;
      vector<link_dat> links;
      for (int j=0; j<m; j++){
	int l, u, r, d; cin>>l>>u>>r>>d;
	string p; cin>>p;
	links.push_back(link_dat(l, u, r, d, p));
      }
      page[name]=links;
    }
    vector<string> hist;
    hist.push_back(home);
    int cursor=0;

    int m; cin>>m;
    for (int i=0; i<m; i++){
      /*
      for (int j=0; j<hist.size(); j++){
	if (j==cursor) cout<<"* "; else cout<<"  ";
	cout<<hist[j]<<endl;
      }
      cout<<"====="<<endl;
      */

      string cmd; cin>>cmd;
      if (cmd=="show"){
	cout<<hist[cursor]<<endl;
      }
      else if (cmd=="forward"){
	cursor++;
	cursor=min(cursor, (int)(hist.size()-1));
      }
      else if (cmd=="back"){
	cursor--;
	cursor=max(0, cursor);
      }
      else if (cmd=="click"){
	int x, y; cin>>x>>y;
	vector<link_dat> &links=page[hist[cursor]];
	for (int i=0; i<links.size(); i++){
	  if (links[i].in(x, y)){
	    hist.resize(cursor+1);
	    hist.push_back(links[i].p);
	    cursor++;
	    break;
	  }
	}
      }
    }
  }
  return 0;
}