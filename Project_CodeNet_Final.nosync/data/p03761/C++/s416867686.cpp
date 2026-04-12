#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int cnt[1000000];
int main(){
  int n;
  cin >> n;
  string t;
  cin >> t;
  rep(i,t.size()) cnt[int(t[i])]++;

  //for (int i=int('a'); i <= int('z');i++) cout << cnt[i];
  //printf("\n");

  rep(i,n-1){
     int tmp[1000000];
     for (int i=int('a');i <= int('z');i++){
        tmp[int(i)] = 0;
     }
     string s;
     cin >> s;
     rep(i,s.size()){
        tmp[s[i]]++;
     }
     for (int i=int('a');i <= int('z');i++){
        cnt[int(i)] = min(cnt[int(i)],tmp[int(i)]);
     }
     //for (int i=int('a'); i <= int('z');i++) cout << cnt[i];
     //printf("\n");
     //for (int i=int('a');i <= int('z');i++){
     //   cnt[int(i)] = 0;
     //}
     
  }
  string res="";
  char x = 'a';
  char y = 'z'; 
  for (int i = int(x);i <= int(y);i++){
     rep(j,cnt[i]) {
        res+=char(i);
     }
  }
  cout << res << endl;
  return 0;
}

