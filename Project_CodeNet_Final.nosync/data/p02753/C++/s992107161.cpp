#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   string s;
   cin>>s;

   bool ok=false;
   rep(i, s.size()-1) if(s[i]!=s[i+1]) ok=true;

   if(ok) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
   return 0;
}
