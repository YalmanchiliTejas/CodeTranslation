#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int k,count=2,e,f,ans=0,l,m,n;
  string s;
  cin >>s>>k;
  char a,b='0',c='C';
  a = s.at(0);
  for(int i=1;i<s.size();i++){
    if(s.at(i)!='0'&& b=='0'){
      b = s.at(i);
      e = s.size()-count+1;
    }
    else if(s.at(i)!='0'&& b!='0' &&c=='C'){
      c = s.at(i);
      f = s.size()-count+1;
    }
    count++;
  }
  a = a-'0';
  m = b-'0';
  n = c-'0';
  l = s.size()-1;
  if(k==1){
    ans += 9*l+a;    
  }
  else if(k==2){
    ans += l*(l-1)/2*81;
    ans += 9*l*(a-1);
    if(b!='0'){
      ans += 9*(e-1)+m;
    }
  }
  else if(k==3){
    ans += l*(l-1)*(l-2)/2*243;
    ans += l*(l-1)/2*81*(a-1);
    if(b!='0'){
     ans += (e-1)*(e-2)/2*81;
     ans += (m-1)*(e-1)*9;
    }
    if(b!='0'&&c!='C'){
     ans += 9*(f-1)+n;
    }
  }
  else if(k==2  && l==1){
    ans += 9*(a-1)+m;
  }
  cout << ans << endl;
}
  