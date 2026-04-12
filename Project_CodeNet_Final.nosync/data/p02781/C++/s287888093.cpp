#include<bits/stdc++.h>
using namespace std;
int main() {
  string n;
  int k,l,i;
  long a;
  cin>>n>>k;
  a=0;
  l=n.length();
  if (k==1) a+=9*(l-1)+(n.at(0)-'0');
  else if (k==2 && l>=2) {
    a+=81*(l-1)*(l-2)/2+(n.at(0)-'1')*9*(l-1);
    i=1;
    while (i<l && n.at(i)=='0') i++;
    if (i<l) a+=9*(l-i-1)+(n.at(i)-'0');
  }
  else if (k==3 && l>=3) {
    a+=729*(l-1)*(l-2)*(l-3)/6+(n.at(0)-'1')*81*(l-1)*(l-2)/2;
    i=1;
    while (i<l-1 && n.at(i)=='0') i++;
    if (i<l-1) {
      a+=81*(l-i-1)*(l-i-2)/2+(n.at(i)-'1')*9*(l-i-1);
      i++;
      while (i<l && n.at(i)=='0') i++;
      if (i<l) a+=9*(l-i-1)+(n.at(i)-'0');
    }
  }
  cout<<a<<endl;
}