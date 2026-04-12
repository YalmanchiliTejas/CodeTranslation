#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define endl        "\n"
#define inf         10000000002
#define pb          push_back
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define bye         return 0

ll mod=1e9+7;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      //freopen("inputNew.txt", "r", stdin);

      ll n;
      cin>>n;
      ll arr[n];
      loop(i,0,n){cin>>arr[i];}

      ll sum=0;
      for(int i=0,cnt=0; i<n; i++){
           sum=(sum+((cnt*arr[i])%mod))%mod;
           cnt=(cnt+arr[i])%mod;
      }

      cout<<sum<<endl;


      bye;
}
