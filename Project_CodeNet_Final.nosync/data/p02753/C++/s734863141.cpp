#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
typedef long long lli;
typedef long li;
typedef pair<int,int> PI;
typedef pair<long,int> PLI;
typedef pair<int,long> PIL;
typedef pair<long, long> PL;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;
typedef priority_queue<int> PQ;
typedef priority_queue<long> PQL;
typedef priority_queue<long long> PQLL;
#define FAST ios::sync_with_stdio(0)
#define forz(n) for (long i = 0; i < n; i++)
#define forv(i,x,y) for (long i=x; i<y; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define TRAV(it, v) for(auto it = v.begin(); it != v.end(); it++) 
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define SQ(a) (a)*(a)
#define UM unordered_map
#define US unordered_set
#define LB(v,x) lower_bound(v.begin(),v.end(),x);
#define UB(v,x) upper_bound(v.begin(),v.end(),x);
#define CUBE(a) (a)*(a)*(a)
#define SORT(v) sort(v.begin(),v.end());
#define SORTC(v,c) sort(v.begin(),v.end(),c);
#define Pi 3.14159265358979323846
 
 
#define module 1000000007
 
 
lli gcd(lli x,lli y){
    if(x==0) return y;
    return gcd(y%x,x);
}
 
PL Egcd(lli x,lli y){
    if(x==0) return MP(0,1);
    PL t=Egcd(y%x,x);
    return MP(t.S-t.F*(y/x),t.F);
}
 

bool comp(PLL a,PLL b){
    return a.S > b.S;
}
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
void solve2(){
   string str;
   cin>>str;
   if(str=="AAA" || str=="BBB"){
       cout<<"No\n";
   }else{
       cout<<"Yes\n";
   }
   return;
}   
 
int main(){
    FAST;
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //=====================================code starts here
    // lli n;
    // cin>>n;
    // while(n--){
        solve2();
    // }
    
    
    return 0;
}
