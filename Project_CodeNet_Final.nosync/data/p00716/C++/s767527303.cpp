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
  int n;
  cin>>n;
  while(n--){
    int an,y,m;
    cin>>an>>y>>m;
    int ma=0;
    rep(i,m){
      int a=an;
      int b,d;
      double c;
      cin>>b>>c>>d;
      if(!b){
	int par=0;
	rep(j,y){
	  par+=(int)(a*c);
	  a-=d;
	}
	a+=par;
      }else{
	rep(j,y){
	  a+=(int)(a*c)-d;
	}
      }
      ma=max(ma,a);
    }
    cout<<ma<<endl;
  }
	

}