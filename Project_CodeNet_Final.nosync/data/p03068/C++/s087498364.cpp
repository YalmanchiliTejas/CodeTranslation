#include <bits/stdc++.h>
using namespace std;
#define rep for(int i = 0;i<n;i++)
#define put(n) cout << n << endl;

int main(void){
  int n;cin >> n;
  string s;cin >> s;
  int m;cin >> m;
  char a = s.at(m-1);
  rep{
    if(s.at(i) != a){
      s.at(i) = '*';
    }
  }
  
  put(s);
}