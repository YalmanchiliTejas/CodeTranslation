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
  string str;cin>>str;
  bool flag=0,flag2=0;
  for(int i=0;i<str.size()-1;i++){
    if(str[i]=='A'&&str[i+1]=='C')flag=true;
  }
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
