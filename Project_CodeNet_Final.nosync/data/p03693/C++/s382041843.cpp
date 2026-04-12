#include<bits/stdc++.h>
using namespace std;
int main()
{ int a,b,c;
   cin>>a>>b>>c;
   int sum=0;
   sum=(a*100)+(b*10)+c;
   if(sum%4==0)cout<<"YES\n";
   else cout<<"NO\n";

return 0;
}
