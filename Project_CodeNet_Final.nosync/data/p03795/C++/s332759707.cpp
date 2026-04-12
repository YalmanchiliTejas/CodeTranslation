/*@author hussein zayed ;
    ___  ___
   |\  \|\  \
   \ \  \_\  \
    \ \   ___ \USSEIN
     \ \  \\ \ \
      \ \__\\ \_\
       \|__| \|__|
****************************************
*/

#include <bits/stdc++.h>
using namespace std;
#define fr for(int i=0;i<n;++i)
#define fr1 for(int i=1;i<=n;++i)
#define cinA for(int i=0;i<n;++i){cin>>arr[i];}
#define cinA1 for(int i=1;i<=n;++i){cin>>arr[i];}
#define coutA for(int i=0;i<n;++i){cout<<arr[i]<<" ";}
#define ll long long
#define lnarray sizeof(arr)/sizeof(*arr)
#define vi vector<int>
#define vs vector<string>
void Fast()
{
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}
inline int RD()
{
    int i ;
    cin>>i;
    return i;
}

inline float RF()
{
    float i ;
    cin>>i;
    return i;
}

inline double RDO()
{
    double i ;
    cin>>i;
    return i;
}

inline string RS()
{
    string i ;
    cin>>i;
    return i;
}

inline ll RLL()
{
    ll i ;
    cin>>i;
    return i;
}

int cm[200000];

ll sumSet(ll n)
{
    return (1ll*n*(n+1))/2;
}
string s;


bool isPrime(int n)
{
    if(n==1)
        return false;
    for(int i=2; i*i<=n; ++i)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int sumDigit(int n){
int sum =0;
  while (n != 0)
    {
        sum+= + n % 10;
        n = n / 10;
    }
    return sum;
}

ll power2(int n){
  ll ans=(1<<n);
  return ans;
}

ll sumpow2(ll n){
 ll sum=(n*(n+1)*(2*n-1))/6;
 return sum;
}
char arr[101][101];
int main(){
    Fast();
//freopen("output.txt" , "w" , stdout);
//freopen("wall.in" , "r" , stdin);



   int a=RD(),n;
   n=a/15;
   cout<<(a*800)-(n*200);

}
