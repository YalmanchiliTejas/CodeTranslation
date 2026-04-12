#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
 
using namespace std;
 
#define P(p) cout<<(p)<<endl
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return
#define C(i) cin>>i
#define C2(i,j) cin>>i>>j
#define C3(i,j,k) cin>>i>>j>>k
#define C4(i,j,k,m) cin>>i>>j>>k>>m
////////////////////////////////////////////////////////////

int main(){
  int x,y,z;
  C3(x,y,z);
  int a=x-z,b=y+z;
  int bef = 0;
  for(int i = 0 ; i < 100000 ; i++ ){
    if(a<b*i){
      P(bef);
      break;
    }
    bef = i;
  }
  ret 0;
}