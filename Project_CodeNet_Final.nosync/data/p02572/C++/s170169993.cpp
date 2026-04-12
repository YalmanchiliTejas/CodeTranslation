#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define     PI                       acos(-1)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-9);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void GO(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int N=300000+5,mod=1e9+7;
int a[N];
ll arr[N];
ll rng(int a,int b){
  return arr[b]-(a?arr[a-1]:0);
}
int main(){
    GO();

    int T;
   // cin>>T;
   T=1;
    while(T--){

       int n;
       cin>>n;
       ll sum=0;
       for(int i=0;i<n;i++) cin>>a[i],sum+=a[i],arr[i]=sum;
       ll ans=0;
       for(int i=0;i<n;i++){
         ans=(ans+(rng(i+1,n-1)%mod*a[i])%mod)%mod;
       }
       cout<<ans<<"\n";
    }

}



































































