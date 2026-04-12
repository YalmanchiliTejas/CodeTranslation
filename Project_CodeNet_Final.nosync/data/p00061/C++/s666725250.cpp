#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb(in,tmp) in.push_back(tmp)
#define all(in) in.begin(),in.end()
#define PI acos(-1)
using namespace std;
int main(){
  vector<int>num;
  vector<int>su;
  int n,s;
  int co=0;
  char d;
  while(cin>>n>>d>>s,n||s){
    co++;
    pb(num,s);
    pb(su,n);
  }
  rep(i,co){
    rep(j,co-1){
      if(num[j]<num[j+1]){
	swap(num[j],num[j+1]);
	swap(su[j],su[j+1]);
      }
    }
  }
  //rep(i,co)
    //cout<<num[i]<<endl;

  int tmp=num[0];
  num[0]=1;
  int count=1;
  loop(i,1,co){
    if(tmp!=num[i])count++;
    tmp=num[i];
    num[i]=count;
  }
  //rep(i,co)
    //cout<<num[i]<<endl;

  int in;
  while(cin>>in){
    int i;
    for(i=0;i<co;i++)if(su[i]==in)break;
    cout<<num[i]<<endl;
  }


}