#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
string i;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b;
  cin >>a;
  b=a*800;
  a=a/15;
  cout <<b-a*200<<'\n';
  return 0;
}
