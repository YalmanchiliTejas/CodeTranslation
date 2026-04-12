#include<iostream>
using namespace std;
int main(){
  char s;int h,w,ans = 0;cin >> h >> w;
  while(cin >> s){
    if(s=='#') ans++;
  }
  cout << ((ans+1==h+w) ? "Possible":"Impossible") << endl;
}