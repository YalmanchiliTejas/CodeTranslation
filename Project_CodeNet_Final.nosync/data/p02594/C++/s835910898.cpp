/*input
30
*/
 
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ld long double
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vpll vector < pair<long long,long long> >
#define fill(a,val)  memset(a,val, sizeof (a))
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define mp make_pair
#define pb push_back
#define f first
#define se second
#define all(cont) cont.begin(), cont.end()
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MAX   1e9
#define MIN  -1e9
typedef map<long long int, long long int> mpi;
typedef set<long long int> seti;
typedef multiset<long long int> mseti;
typedef priority_queue<long long int> pq;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i, n)    for(long long int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(ll i = a; i <= (n); ++i)
#define repD(i, a, n)  for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define repn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define PI 3.14159265
#define dbg(x) cerr << "\n" << (#x) << " = " << (x) << endl ;
//#define cerr if(false)cerr
 
#define mod 998244353
 
struct node{
    ll val;
};
struct Interval {int start, end;};
bool compare(struct node n1, struct node n2) {
    return (n1.val < n2.val);
}
 
 
 ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 





 
int main() 
{
    ll x; cin>>x;
    if(x>=30)
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;
    return 0;  
}
 