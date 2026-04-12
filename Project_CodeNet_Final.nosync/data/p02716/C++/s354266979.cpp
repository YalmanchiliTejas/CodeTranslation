#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    clr(v,d)      memset( v, d ,sizeof(v))
typedef  long long     ll ;
typedef  unsigned long long ull;
const double EPS= (1e-9);
using namespace std;
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(int num, int idx) {return num ^ (1<<idx);}
void GO(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=200000+9;
const ll inf=1e15;
int arr[N];
ll mem[N][5],n;
ll solve(int id,int f){

   if(id>=n){
     if(n%2==0)
    return 0;
     if(f!=2) return 0;
     return -inf;
   }
   ll &ret=mem[id][f];
   if(ret!=-inf) return ret;

   ll ans=-inf;
   ans=max(ans,arr[id]+solve(id+2,f));
   if(f)
   ans=max(ans,solve(id+1,f-1));
   return ret=ans;
}
int main(){
    GO();
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<=n;i++) for(int j=0;j<5;j++) mem[i][j]=-inf;
    cout<<solve(0,(n%2==0?1:2))<<"\n";
}


















