#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define int long long
#define gok ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define mo 1000000007

signed main(){
    gok
   int c=0;
   string s;
   cin>>s;
   for(int i=0;i<s.size();i++)
   {
       if(s[i]=='A')
        c++;
   }
     if(c==3 || c==0)
            cout<<"No";
     else
        cout<<"Yes";
    return 0;
}
