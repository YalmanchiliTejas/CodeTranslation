#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main() {

   string s;
   cin>>s;

   int a=0,b=0;

  for(int i=0;i<s.length();i++){
    if(s[i] == 'A')
        a++;
    else if(s[i] == 'B')
        b++;
  }

  if(a>0 && b>0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

  return 0;
}