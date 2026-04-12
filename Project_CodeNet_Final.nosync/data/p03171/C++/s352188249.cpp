#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define ld long double
#define ull unsigned long long
#define mp make_pair
#define pb(x) push_back(x)
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>
#define mll map<long long ,long long>
#define flsh fflush(stdout)
#define gcd __gcd
#define clr(x) memset(x,0,sizeof(x))
#define mod 1000000007LL
#define INF 1000000000007


 
//     long long power(long long x, long long y, long long p) 
// { 
//     long long res = 1;      
  
//     x = x % p;  
  
//     while (y > 0) 
//     { 
      
//         if (y & 1) 
//             res = (res*x) % p; 

//         y = y>>1; 
//         x = (x*x) % p; 
//     } 
//     return res; 
// } 
  

// long long modInverse(long long n, long long p) 
// { 
//     return power(n, p-2, p); 
// }  

// long long ncrp(long long n, long long r, long long p) 
// { 
   
//    if (r==0) 
//       return 1; 
  
    
//     long long fac[n+1]; 
//     fac[0] = 1; 
//     // for (long long i=1 ; i<=n; i++) 
//     //     fac[i] = fac[i-1]*i%p; 
  
//     return (fac[n]* modInverse(fac[r], p) % p * 
//             modInverse(fac[n-r], p) % p) % p; 
// }




int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


   if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }


   ll n;
   cin>>n;

   ll i;

   vll v;


   while(n--)
   {
       ll x;
       cin>>x;

       v.pb(x);
       ll siz=v.size();

       while(siz>2&&v[siz-3]<=v[siz-2]&&v[siz-2]>=v[siz-1])
       {
           ll no=v[siz-1]+v[siz-3]-v[siz-2];

           for(i=0;i<3;i++)
           {
               v.pop_back();
           }
           v.pb(no);
           siz-=2;
       }
   }

   deque<ll> d;

   for(auto it:v)
   {
    //    cout<<it<<" ";
       d.pb(it);
   }
//    cout<<endl;

   ll sum=0;
   ll z=1;
   while(d.size())
   {
       if(d.front()>=d.back())
       {
           sum+=d.front()*z;
           d.pop_front();
       }
       else{
           sum+=d.back()*z;
           d.pop_back();
       }
       z*=-1;
   }

   cout<<sum<<endl;


    
 

  

    return 0;
}