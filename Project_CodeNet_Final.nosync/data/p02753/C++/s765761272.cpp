#include<bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
const int mod=1e9+7;
const int inf=1e17+10;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define si(a) a.size()
#define pii pair<int,int>
using namespace std;



int32_t main() {
   std::ios::sync_with_stdio(false);cin.tie(NULL);
   string s;
   cin>>s;
   int a=0,b=0;
   for(char c:s)
   {
       if(c=='A')a++;
       else b++;
   }
   if(a&&b)cout<<"Yes\n";
   else cout<<"No\n";
   return 0;
}
