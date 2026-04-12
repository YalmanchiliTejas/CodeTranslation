#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#define ll long long int
using namespace std;
int main(void) {
  char r, g, b;
  cin>>r>>g>>b;
  int x=100*(r-'0')+10*(g-'0')+b-'0';
  if(x%4==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
