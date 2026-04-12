#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void gcd(vector<int> &a, string buf){
  vector<int> bufs(26);
  int num;
  for (int i=0; i<buf.size(); i++){
    num = (int)(buf.at(i)-'a');
    bufs.at(num)++;
  }
  for (int i=0; i<26; i++){
    a.at(i) = min(a.at(i), bufs.at(i));
  }
}

int main() {
  int n; cin >>n;
  string buf;
  vector<int> a(26, 50);// アルファベットn文字がm子あるよ
  for (int i=0; i<n; i++){
    cin >>buf;
    gcd(a, buf);
  }
  int tsize = 0;
  for (int i=0; i<26; i++){
    tsize += a.at(i);
  }
  
  vector<char> t(tsize);
  int tindex = 0;
  for (int i=0; i<26; i++){
    for (int j=0; j<a.at(i); j++){
      t.at(tindex) = (char)(i+'a');
      tindex++;
    }
  }
  for (int i=0; i<tsize; i++){
    cout <<t.at(i);
  }
  
  //cout <<ans;
  cout <<endl;
}
