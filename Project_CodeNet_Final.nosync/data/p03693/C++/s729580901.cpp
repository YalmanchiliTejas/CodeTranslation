#include<iostream>
#include<deque>
#include<cmath>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<ios>
#include<sstream>
#include<locale>
using namespace std;
#define ive(cris) int long long 
#define in(out) long double
#define INF 100000007
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if((a*100+b*10+c)%4==0){
    cout<<"YES"<<'\n';
  }
  else{
    cout<<"NO"<<'\n';
  }
  return 0;
}
