#include"bits/stdc++.h"
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20)
#define ll long long
#define endl '\n'
//       Author
//        ::
//    (  NOBODY  )
//   No Copyright .....You can copy and paste it without my permission...................................
// !!!!!!!!!!!!!!!
#define pb push_back
#define N 300009
int a[N],b[N],c[N];
int dp[40008][102][3];
int mo=1e9+7;
int n;
vector<int>v;
ll digit(int indx,int sum,int ok,int div)
{
   if(indx==-1)return (sum%div==0);
   if(dp[indx][sum][ok]!=-1)return dp[indx][sum][ok];
   int num=(ok)?v[indx]:9;
   ll sm=0;
   for(int i=0;i<=num;i++)
   {
     int new_ok=(i==v[indx])?ok:0;
     sm+=(ll)digit(indx-1,(sum+i)%div,new_ok,div);
     if(sum+i==0&&indx==n-1)sm--;
     sm%=mo;
   }
   if(!ok)dp[indx][sum][ok]=sm;
   return (sm%mo);

}
int main()
{
    FAST_IO;
    string s;
    memset(dp,-1,sizeof(dp));
    int k;
    cin>>s>>k;
     n=s.size();
    for(int i=n-1;i>=0;i--)
    {
      v.pb(s[i]-'0');
      //cout<<v.back()<<" ";
    }
   cout<< digit(n-1,0,1,k)%mo;
    return 0;
}
