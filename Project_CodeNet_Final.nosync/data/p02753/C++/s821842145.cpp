#include<bits/stdc++.h>
using namespace std;
int main()
{string s;cin>>s;
 int a=count(s.begin(),s.end(),'A'),b=count(s.begin(),s.end(),'B');
 if(a==0 || b==0)cout<<"No";
 else cout<<"Yes";
  return 0;
}
