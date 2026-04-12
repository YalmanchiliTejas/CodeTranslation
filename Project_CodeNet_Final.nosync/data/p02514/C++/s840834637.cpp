#include<iostream>
#include<vector>
using namespace std;

struct point {
  int x;
  int y;
};

struct page{
  string name;
  vector< pair<point,point> > button;
  vector<string> link;

  string click(int x,int y) {
    for(int i=0; i<button.size(); i++) {
      if(button[i].first.x <= x && button[i].second.x >= x)
	if(button[i].first.y <= y && button[i].second.y >= y)
	  return link[i];
    }
    return "Not Found.";
  }
};

int main() {

  int n,w,h;
  while(true) {
    cin>>n;
    if(n==0) break;
    cin>>w>>h;

    vector<struct page> p;
    string s;
    int d;
    for(int i=0; i<n; i++) {
      struct page k;
      cin>>k.name>>d;
      for(int j=0; j<d; j++) {
	point r,l;
	cin>>r.x>>r.y>>l.x>>l.y>>s;
	pair<point,point> po;
	po.first=r,po.second=l;
	k.button.push_back(po);
	k.link.push_back(s);
      }
      p.push_back(k);
    }

    int m;
    cin>>m;

    string op;
    vector<struct page> buff;
    buff.push_back(p[0]);
    int curr=0;
    for(int i=0; i<m; i++) {
      cin>>op;
      if(op=="show") {
	cout<<buff[curr].name<<endl;
      }else if(op=="forward") {
	if(curr+1<buff.size())
	  curr++;
      }else if(op=="back") {
	if(curr!=0)
	  curr--;
      }else if(op=="click") {
	int x,y;
	cin>>x>>y;
	string next = buff[curr].click(x,y);
	if(next != "Not Found.") {
	  buff.resize(curr+1);
	  for(int i=0; i<p.size(); i++) {
	    if(p[i].name == next) {
	      buff.push_back(p[i]);
	      curr++;
	    }
	  }
	}
      }

    }

  }
	
}