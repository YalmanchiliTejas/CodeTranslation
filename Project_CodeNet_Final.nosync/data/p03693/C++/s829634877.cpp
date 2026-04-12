#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>


typedef long long ll;
#define fi first
#define se second
const ll mod = 1000000007;
//              123456789

using namespace std;

///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////



pair<int, int>p[112345];

int r;
int g;
int b;
int sum;

int main(){
  
  cin>>r>>g>>b;
  
  sum = 100*r+10*g+b;
  
  if( sum % 4 ){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
  }
  
  
  return 0;
}