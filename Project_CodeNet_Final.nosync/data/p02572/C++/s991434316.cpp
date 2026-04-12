
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

double eps = 1e-9;
int change(string a,string b)
{
    int cnt=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!=b[i])
        {
            cnt++;
        }
    }
    return cnt;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   int n;
   ll m = 1e9 + 7;
   cin>>n;
   ll arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   ll pref[n];
   pref[0]=arr[0]%m;
   for(int i=1;i<n;i++)
   {
       pref[i] = (arr[i]%m+pref[i-1])%m;
   }
   ll ans=0;
   for(int i=0;i<n-1;i++)
   {
      ans += (arr[i]%m * (pref[n-1]%m-pref[i+1]%m+arr[i+1]%m)%m)%m;
   }
   cout<<ans%m<<endl;




}

