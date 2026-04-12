#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
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
 string s;
 cin>>s;
 int n=3,count=0,count1=0;
 for(int i=0;i<n;i++)
 {if(s[i]=='A')
  count++;
  else
  count1++;
}
if(count==0||count1==0)
cout<<"No";
else
cout<<"Yes";
}
