#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define pb push_back
#define mod 1000000007
using namespace std;
typedef long long int ll;

int main(void){
  string s;
  cin>>s;
  string ac="AC";
  for(int i=0;i<s.size()-1;i++){
    if(ac==s.substr(i,2)){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}
