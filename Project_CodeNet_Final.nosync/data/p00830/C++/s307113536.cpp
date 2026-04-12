#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

vector<int> id[10000];
vector<string> c[10000];
int p[10000];
string name[10000];
int n,m;
string a,b;

int search(string s){
  int cur = 0;
  string tmp = "";
  for(int i=1;i<s.size();i++){
    if(s[i]=='/'){
      if(tmp=="."){
	if(id[cur].empty())return -1;
	tmp = ""; continue;
      }
      if(tmp==".."){
	if(cur == 0)return -1;
	if(id[cur].empty())return -1;
	cur = p[cur]; tmp = ""; continue;
      }

      bool f = false;
      for(int j=0;j<c[cur].size();j++){
	if(c[cur][j] == tmp){
	  cur = id[cur][j];
	  f = true;
	  break;
	}
      }
      if(!f)return -1;
      tmp = "";
    }else{
      tmp += s[i];
    }
  }
  
  if(tmp.size()){
    if(tmp=="."){
      if(id[cur].empty())return -1;
    }else if(tmp==".."){
      if(cur==0)return -1;
      if(id[cur].empty())return -1;
      cur = p[cur];
    }else{
      bool f = false;
      for(int i=0;i<c[cur].size();i++){
	if(c[cur][i] == tmp){
	  cur = id[cur][i];
	  f = true;
	  break;
	}
      }
      if(!f)return -1;
    }

    if(id[cur].empty())return cur;

    for(int i=0;i<c[cur].size();i++){
      if(c[cur][i] == "index.html"){
	if(id[id[cur][i]].empty())return id[cur][i];
	return -1;
      }
    }
    return -1;
  }else{
    if(id[cur].empty())return -1;

    for(int i=0;i<c[cur].size();i++){
      if(c[cur][i] == "index.html"){
	if(id[id[cur][i]].empty())return id[cur][i];
	return -1;
      }
    }
    return -1;
  }
}
int main(){

  while(cin >> n >> m ,n){
    for(int i=0;i<10000;i++){
      id[i].clear(); c[i].clear();
    }

    int num = 1;
    for(int i=0;i<n;i++){
      cin >> a;
      string tmp;
      int cur = 0;
      for(int i=1;i<a.size();i++){
	if(a[i]=='/'){
	  bool f = false;
	  for(int j=0;j<c[cur].size();j++){
	    if(c[cur][j] == tmp){
	      cur = id[cur][j];
	      f = true;
	      break;
	    }
	  }
	  if(!f){
	    id[cur].push_back(num);
	    c[cur].push_back(tmp);
	    p[num] = cur;
	    name[num] = tmp;
	    cur = num;
	    num++;
	  }
	  tmp = "";
	}else{
	  tmp += a[i];
	}
      }
      
      if(tmp.size()){
	id[cur].push_back(num);
	c[cur].push_back(tmp);
	p[num] = cur;
	name[num] = tmp;
	num++;
      }
    }

    for(int i=0;i<m;i++){
      cin >> a >> b;
      int aid = search(a), bid = search(b);
      if(aid == -1 || bid == -1){
	cout << "not found\n";
      }else cout << ((aid==bid)?"yes":"no") << endl;
    }
  }
}