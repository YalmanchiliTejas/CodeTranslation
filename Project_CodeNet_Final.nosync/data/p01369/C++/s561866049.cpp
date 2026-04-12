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
  string left="mnlkjhyuiop";
  string s;
  while(cin>>s,s.size()!=1||s[0]!='#'){
    bool h=true;//r
    int co=-1;
    rep(i,11){if(left[i]!=s[0])continue;co++;break;}
    rep(i,s.size()){
      bool han=true;
      if(h){han=false;rep(j,11)if(left[j]==s[i])han=true;}
      else {rep(j,11)if(left[j]==s[i])han=false;}
      if(!han){co++;h^=1;}
      //cout<<h<<endl;
    }
    cout<<co<<endl;
  }

}