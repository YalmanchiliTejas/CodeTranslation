#include <bits/stdc++.h>
using namespace std;
const int mod =  1000000007;
const int LIM = 100005;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mem(a,b) memset(a,b,sizeof(a))
#define all(a) a.begin() , a.end()
#define vvi vector<vector<int>>
//#define double long double
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define endl '\n'
#define pb push_back
#define sp <<" "<<
#define ss second
#define ff first
int power(int x, int n){
    int res = 1;
    while(n){
          if(n&1){
                res = res * x % mod;
          }
          x = x * x % mod;
          n>>=1;
    }
    return res;
}

int32_t main()
{     //IOS;
      int tt=1,n,k,x,y,z,i,j;
      //cin>>tt;
      while(tt--)
      {
        cin>>n;
        if(n>=30)
        cout<<"Yes";
        else
        cout<<"No";
      }
}
