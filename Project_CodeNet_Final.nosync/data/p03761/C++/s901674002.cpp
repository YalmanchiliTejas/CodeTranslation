#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string c;
string f(string a, string b)
{
  c="";
  int p1=0,p2=0;
  while(1){
    if(p1==a.size())return c;
    if(p2==b.size())return c;
    if(a[p1]==b[p2]){
      c.push_back(a[p1]);
      p1++;p2++;
    } else if(a[p1]>b[p2]) {
      p2++;
    } else {
      p1++;
    }
  }
}
  




int main(void)
{
  string s[55];
  string buf;
  int n;cin >>n;
  for(int i=0;i<n;i++){
    cin >> s[i];
    sort(s[i].begin(),s[i].end());
    if(i>0){
      buf=f(s[i],s[i-1]);
      s[i]=buf;
    }
  }
  if(n==1)buf=s[0];
  cout << buf << endl;
}








