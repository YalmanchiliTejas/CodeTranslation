#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;


//      DEEP

using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) v.begin(),v.end()
#define pb push_back
#define endl '\n'
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pll;
typedef set<int> si;




/*
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
*/
/*
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
*/

const ll mod = 1e9 + 7;
const ll mod1=998244353;
const double pie=3.1415926535;
                                                    //power
ull power(ull x,ull y){
   if(y==0) return 1;
   else{
     if(y%2==0) return power(x*x,y/2);
     else return x*power(x*x,(y-1)/2);
   }
}

                        //                    Modular Exponentiation

ll mod_power(ll x, ll y, ll m)
{
    ll r = 1;     // Initialize result

    x = x % m; // Update x if it is more than or equal to m

    if (x == 0) return 0; // In case x is divisible by m;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            r = (r*x) % m;

        // y must be even now
        y = y/2;
        x = (x*x) % m;
    }
    return r;
}

                                                      //GCD
ll gcd(ll x,ll y){
   if(y==0)return x;
   return gcd(y,x%y);
}
                                              // SIEVE

/*
bool isPrime[1000001];
void sieve(int N) {

        for(int i = 0; i <= N;++i) {
            isPrime[i]=true;
        }
        isPrime[0]=false;
        isPrime[1]=false;

        for(int i = 2; i * i <= N; ++i) {
             if(isPrime[i] == true) {
                 for(int j = i * i; j <= N ;j += i)
                     isPrime[j] = false;
            }
        }
    }
*/
/*
const int N=100001;
ll fact_inverse[N];
ll num_inverse[N];
ll fact[N];
void number_inverse(int m){
   num_inverse[0]=1;
   num_inverse[1]=1;
   for(int i=2;i<=N;i++){
     num_inverse[i]=num_inverse[m%i]*(m - m/i)%m;
   }
}

void factorial_inverse(int m){
   fact_inverse[0]=1;
   fact_inverse[1]=1;
   for(int i=2;i<=N;i++){
      fact_inverse[i]=(num_inverse[i]*fact_inverse[i-1])%m;
   }
}

void factorial(int m){
  fact[0]=1;
  for(int i=1;i<=N;i++)fact[i]=(i*fact[i-1])%m;
}

int modular_nCr(int n,int r,int m){
   ll res=((fact[n]*fact_inverse[r])%m *  fact_inverse[n-r])%m;
   return res;
}
*/

int main(){
    boost;
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--){
       ll n,x,m;
       cin>>n>>x>>m;
       if(x==0){
        cout<<0<<endl;
        return 0;
       }
       if(m==1){
        cout<<x<<endl;
        return 0;
       }
       unordered_map<ll,ll>M;
       ull ans=x;
       M[x]++;
       ull zero=0;
       ull k=1;
       ull ele;
       while(k<n){
          ull y=((x%m)*(x%m))%m;
          if(y==0){
            zero++;
            break;
          }
          if(M[y]==1){
            ele=y;
            break;
          }
          ans+=y;
          x=y;
          M[y]++;
          k++;
       }
       if(zero){
        cout<<ans<<endl;
        return 0;
       }
       if(k==n){
        cout<<ans<<endl;
        return 0;
       }
       vector<ull>presum;
       presum.pb(ele);
       ull z=ele;
       ans+=z;
       bool ok=false;
       ull j=k;
       j++;
       while(j<n){
         ull y=((z%m)*(z%m))%m;
         ans+=y;
         if(y==ele)break;
         ull kk=y + presum[presum.size()-1];
         presum.pb(kk);
         z=y;
         j++;
       }
       if(j==n){
        cout<<ans<<endl;
        return 0;
       }
       ans-=ele;
       ans-=presum[presum.size()-1];
       ull done=n-k;
       ull temp=done/presum.size();
       ans+=((presum[presum.size()-1]) * (temp));
       
       ull r=done%(presum.size());
       if(r>0)ans+=presum[r-1];
       
       cout<<ans<<endl;
       


 }
}