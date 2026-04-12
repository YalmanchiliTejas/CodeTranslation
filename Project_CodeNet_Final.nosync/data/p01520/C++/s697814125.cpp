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
  int a,b,c;
  cin>>a>>b>>c;
  bool han=false;
  rep(i,a){
    int in;
    cin>>in;
    for(int j=b-c;j<=b+c;j++)
      if((double)j/in-j/in==0){han=true;break;}
    if(han){cout<<i+1<<endl;break;}
  }
  if(!han)cout<<"-1"<<endl;

}