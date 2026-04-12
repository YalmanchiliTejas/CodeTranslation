#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define mod 1000000007


int main(){
  ll n;
  cin >>n;
  string s;
  cin >>s;
  ll k;
  cin >>k;
  char res=s[k-1];
  rep(i,n){
    if(s[i]!=res)s[i]='*';
  }
  cout << s << endl;
}
