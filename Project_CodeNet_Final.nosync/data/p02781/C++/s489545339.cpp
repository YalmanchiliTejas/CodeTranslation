#include <bits/stdc++.h>
using namespace std;
string n,s="";
long k,ans=0;
void aaa(long a,string b) {
  for(long i=n.size()-1;i>=0;i--) {
    if(b[i]=='0'&&(i==0||a>1)) {
      for(char j='1';j<='9';j++) {
        b[i]=j;
        if(a==k) {
          if(b<=n) ans++;
          else break;
        } else {
          if(b<=n) aaa(a+1,b);
          else break;
        }
      }
      b[i]='0';
    } else if(a>1) {
      return;
    }
  }
  return;
}
int main() {
  cin >> n >> k;
  for(long i=k;i<n.size();i++) {
    if(k==1) ans+=9;
    if(k==2) ans+=81*(i-1);
    if(k==3) ans+=729*(i-1)*(i-2)/2;
  }
  for(long i=0;i<n.size();i++) s=s+"0";
  if(k<=n.size())aaa(1,s);


  cout << ans << endl;
}