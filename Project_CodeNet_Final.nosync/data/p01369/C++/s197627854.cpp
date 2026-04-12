#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

std::string l = "qwertasdfgzxcvb",r = "yuiophjklnm";

int han(string s){
  rep(i,l.size()){
    if(l.substr(i,1) == s) return 1;
  }
  return 0;
}

int main(){
  string s;
  while(cin >> s){
    if(s== "#") break;
    int pre = han(s.substr(0,1)),ans=0;
    rep(i,s.size()){
      if( pre != han(s.substr(i,1)) ){
	ans++;
	pre = han(s.substr(i,1));
      }
    }
    cout << ans << endl;
  }

}