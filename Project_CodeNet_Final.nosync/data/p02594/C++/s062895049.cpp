#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power(ll a,ll b)
{ll result=1;
while(b>0)
{if(b%2==1)
 result*=a;
 a*=a;
 b/=2;
}
return result;
}
int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int x;
cin>>x;
if(x>=30)
cout<<"Yes";
else
cout<<"No";
}