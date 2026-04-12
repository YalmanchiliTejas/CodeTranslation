#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<cstdio>

using namespace std;

typedef pair<int,int> P;

typedef pair<P,P> L;

bool isIn(L l,P p){
  P lu=l.first,rb=l.second;
  if(lu.first  <= p.first  &&
     lu.second <= p.second &&
     rb.first  >= p.first  &&
     rb.second >= p.second )
    return true;
  else
    return false;
}

typedef map<string,vector<pair<L,string> > > mm;

int main(){
  int n;
  while(cin>>n,n){
    int w,h;
    mm pages;
    cin >> w >> h;
    string now;
    for(int i=0;i<n;i++){
      string name;
      int c;
      cin >> name >> c;
      if(i==0) now = name;

      for(int j=0;j<c;j++){
	P p1,p2;
	string s;
	cin >> p1.first >> p1.second >> p2.first >> p2.second >> s;
	pages[name].push_back(make_pair(make_pair(p1,p2),s));
      }
    }
    int cs;
    vector<string> s(6000);
    int st = 0,sm = 0;
    s[st]=now;
    cin >> cs;
    while(cs-->0){
      string command;
      cin >> command;
      //cout << st << ":" << sm << ":" << command << endl;
      if(command == "click"){
	P p;
	cin >> p.first >> p.second;
	vector<pair<L,string> > v = pages[now];
	for(int i=0;i<v.size();i++){
	  if(isIn(v[i].first,p)){
	    now = v[i].second;
	    s[++st]=now;
	    sm = st;
	    break;
	  }
	}
      }else if(command == "back"){
	now = s[(st=(st==0?0:st-1))];
      }else if(command == "forward"){
	now = s[(st=(st==sm?sm:st+1))];
      }else if(command == "show"){
	cout << now << endl;
      }else{
	continue;
      }
    }
  }
  return 0;
}