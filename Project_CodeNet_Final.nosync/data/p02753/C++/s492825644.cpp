#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
  string s ;
  cin >>s ;
  char a =s[0];
  char b =s[1];
  char c =s[2];
  if(a==b&&a==c&&b==c){
    cout <<"No"<<endl;
    return 0;
  }
  cout <<"Yes"<<endl;
  return 0;
  
}
