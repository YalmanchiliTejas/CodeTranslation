#include<bits/stdc++.h>
using namespace std;

int v,e;
char a[100100];
vector<int> g[100100];

int main(){
  cin >> v >> e;
  for(int i=0;i<v;i++)cin >> a[i];
  for(int i=0;i<e;i++){
    int s,t;
    cin >> s >> t;
    g[s].push_back(t); g[t].push_back(s);
  }

  for(int i=0;i<v;i++){
    if(a[i] == '?'){
      bool use[30] = {};
      for(int j=0;j<(int)g[i].size();j++){
	int u = g[i][j];
	if(a[u] != '?')use[a[u]-'a'] = true;
      }
      
      for(int j=0;j<26;j++){
	if(!use[j]){
	  cout << (a[i] = (char)('a' + j));
	  break;
	}
      }
    }else cout << a[i];
  }
  cout << endl;
}
