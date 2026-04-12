#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,x,n) for(int i=x;i<n;++i)
#define ar array
void func(int n){
    for(int i=0;i<=n;++i)
        cout<<i<<" ";
    for(int i=n-1;i>=0;--i)
        cout<<i<<" ";
    cout<<endl;
}
int32_t main()
{
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<s.size();++i){
      if(s[i]=='A')
        a++;
      else ++b;
    }
    if(a>0 && b>0)
      cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
