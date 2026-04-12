#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1e9+7
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
  string s;
  while(cin>>s,s!="#"){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    vector<string>str;
    string now="";
    for(int i=0;i<s.size();i++){
      if(s[i]=='/'){
	str.pb(now);
	now="";
      }else{
	now+=s[i];
      }
    }
    str.pb(now);
    vector<vector<char> >vvc(str.size());
    for(int i=0;i<str.size();i++){
      for(int j=0;j<str[i].size();j++){
	if(isdigit(str[i][j])){
	  for(int k='0';k<str[i][j];k++)
	    vvc[i].pb('.');
	}else{
	  vvc[i].pb('b');
	}
      }
    }
    vvc[a][b]='.';
    vvc[c][d]='b';
    // for(int i=0;i<vvc.size();i++){
    //   for(int j=0;j<vvc[i].size();j++)
    // 	cout<<vvc[i][j];
    //   cout<<endl;
    // }
    vector<string>ans;
    for(int i=0;i<vvc.size();i++){
      string str2="";
      int cnt=0;
      for(int j=0;j<vvc[i].size();j++){
	while(j<vvc[i].size()&&vvc[i][j]=='.'){
	  cnt++;
	  j++;
	}
	if(cnt>0)
	  str2+=(char)(cnt+'0');
	if(j!=vvc[i].size())
	  str2+=vvc[i][j];
      cnt=0;
      }
      ans.pb(str2);
    }

    for(int i=0;i<ans.size();i++){
      cout<<ans[i];
      if(i!=ans.size()-1)
	cout<<'/';
    }
    cout<<endl;
  }
  return 0;
}
