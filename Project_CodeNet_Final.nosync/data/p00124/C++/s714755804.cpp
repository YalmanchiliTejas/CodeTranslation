#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#define pb(in,tmp) in.push_back(tmp)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) loop(i,0,b)
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
using namespace std;
int main(){
  int n;
  bool h=false;
  while(cin>>n,n){
    if(h)cout<<endl;
	h=true;
    vector<string>s(n);
	vector<int>t(n);
	rep(i,n){
	  int a,b,c;
	  cin>>s[i]>>a>>b>>c;
	  t[i]=3*a+c;
	}
	rep(i,n){
	  rep(j,n-i-1){
	    if(t[j]<t[j+1]){
		  swap(t[j],t[j+1]);
		  swap(s[j],s[j+1]);
		}
      }
	}
	rep(i,n)cout<<s[i]<<','<<t[i]<<endl;
	
  }
}