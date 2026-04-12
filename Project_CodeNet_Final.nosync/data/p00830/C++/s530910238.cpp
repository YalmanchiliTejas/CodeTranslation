#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

string replacedelim(string t){
  string tt=t;
  replace(begin(tt),end(tt),'/',' ');
  return tt;
}  

int main(){
  for(int n,m;cin>>n>>m,n;){
    set<string> s;
    set<vector<string> > dirs;
    while(n--){
      string t;
      cin>>t;
      s.insert(t);
      stringstream ss(replacedelim(t));
      vector<string> v;
      for(string s;ss>>s;){
	v.push_back(s);
      }
      vector<string> w;
      for(int i=0;i+1<v.size();i++){
	w.push_back(v[i]);
	dirs.insert(w);
      }
    }
    while(m--){
      bool f=false;
      set<string>::iterator it[2];
      for(int i=0;i<2;i++){
	string t;
	cin>>t;
	stringstream ss(replacedelim(t));
	vector<string> v;
	vector<vector<string> > vs;
	for(string st;ss>>st;){
	  if(st==".."){
	    if(v.empty()){
	      f=true;
	    }else{
	      v.pop_back();
	    }
	  }else if(st!="."){
	    v.push_back(st);
	    vs.push_back(v);
	  }
	}
	for(int j=0;j+1<vs.size();j++){
	  f|=vs.size()&&!dirs.count(vs[j]);
	}
	string pt;
	for(auto e:v){
	  pt+="/"+e;
	}
	bool es=t.back()=='/'||t.back()=='.';
	f|=es&&!vs.empty()&&!dirs.count(vs.back());
	if(!es){
	  it[i]=s.find(pt);
	}
	if(es||it[i]==end(s)){
	  it[i]=s.find(pt+"/index.html");
	}
      }
      cout<<((f||it[0]==end(s)||it[1]==end(s))?"not found":
	     (it[0]==it[1])?"yes":"no")<<endl;
    }
  }
}