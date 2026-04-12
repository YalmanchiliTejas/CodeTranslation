#include<bits/stdc++.h>
 using namespace std;
 #define ll long long int
 int main()
  {   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       ll b,c=0,x,i,j,n;
        cin>>n;
         ll a[n],sum=0;
          for(i=0;i<n;i++)
             {cin>>a[i];
              sum+=a[i];
             }
           for(i=0;i<n-1;i++)
             {  sum-=a[i];
               c+=((sum%1000000007)*((a[i])%1000000007))%1000000007;
             }
             cout<<c%1000000007<<endl;
        }
