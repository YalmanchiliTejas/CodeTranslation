/*......................*/
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double   ld;

//#include <ext/pb_ds/assoc_container.hpp>   
//#include <ext/pb_ds/tree_policy.hpp>  
//#include <functional> 
//using namespace __gnu_pbds;  
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> OST;           //unique elements  

#define    f(i,j,n)                 for(int i = j; i <= n; i++)
#define    r(i,n,j)                 for(int i = n; i >= j; i--)
#define    mod                      1000000007
#define    speed                    ios_base::sync_with_stdio(false);
#define    upp                       cin.tie(NULL);
#define    pb                       push_back
#define    mp                       make_pair
#define    T                        int t; cin >> t; while(t--)
#define    ff                       first
#define    ss                       second
#define    all(container)           container.begin() , container.end()
#define    sz(container)            (int)container.size()
#define    pii                      pair <int , int>
#define    pll                      pair <long long int , long long int>
#define    ook(x)                   order_of_key(x)
#define    fbo(x)                   find_by_order(x)

multiset <ll> ms;
ll arr[100005];
int ans = 0 , n;

int main(){                                       //constraints , long long
     speed upp
     cin >> n;
     f(i,1,n){
         cin >> arr[i];
     }
     r(i,n,1){
         ll x = arr[i];
         auto it = ms.upper_bound(x);
         if(it == ms.end()){
             ans++;
             ms.insert(x);
         }
         else{
             ms.erase(it); 
             ms.insert(x);
         }
     }
     cout << ans << '\n';
}