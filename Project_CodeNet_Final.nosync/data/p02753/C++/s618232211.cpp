#include <bits/stdc++.h>  
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define forn(i,a,b)        for( i = a ; i < b  ; i++ )
#define debug(x)           cout << #x << " " << x << " -- "
#define I__O               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll                 long long  
#define p(x)               cout << x << "\n" ; 
#define MOD                100000007
#define pi                 pair<int,int>
#define vi                 vector <int>
#define pb                 push_back
#define vp                 vector <pair<ll,ll>>
#define endl               cout << "\n"
#define mi                 map <int,int> 
#define f1                 first 
#define s1                 second    
#define in                 insert
#define all(x)             x.begin(),x.end() 
using namespace std ; 
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set ; 
const int N = 2e5;  
const double pie = 3.14159265358979323846 ;
// limit for array size 
double dist(double Ax,double X,double Ay, double Y){
  double best = (Ax-Ay)*(Ax-Ay) + (X-Y)*(X-Y) ;
  best = sqrt(best) ;
  return best ;
}
int tests(){ 
  // vector <vector <int>> M(3,vector <int> (3,271)) ;
  string s ;
  cin >> s ;
  int i = 0 ;
  set <int> S ;
  for(auto it : s )
    S.insert(it) ;
  if(S.size() == 1 )
    return cout << "No\n",0 ; 
  
  cout << "Yes\n" ; 
  return 0 ;
}
int main(){
    I__O ;  
    int cases = 1 ;
    // cin >> cases ; 
    while(cases--)
      tests(); 
    return 0 ; 
}