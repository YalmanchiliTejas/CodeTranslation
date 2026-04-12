#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  string s;
  cin >> n >> s >> k;
  char a = s[k-1];
  rep(i,n){
    if(s[i]!=a){
      s[i] = '*';
    }
  }
  cout << s << endl;
  
  return 0;
}