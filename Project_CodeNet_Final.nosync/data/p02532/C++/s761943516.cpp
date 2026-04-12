#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
  string s;
  int n;
  cin>>n;
  vector<vector<string> >in(n+1);
  while(cin>>s,s!="quit"){
    if(s=="push"){
      cin>>n>>s;
      in[n].pb(s);
    }else if(s=="pop"){
      cin>>n;
      cout<<in[n][in[n].size()-1]<<endl;
      in[n].pop_back();
    }else if(s=="move"){
      cin>>n;
      string tmp=in[n][in[n].size()-1];
      in[n].pop_back();
      cin>>n;
      in[n].pb(tmp);
    }
  }
}