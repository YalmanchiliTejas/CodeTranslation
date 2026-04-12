//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(intl i=0,nn=(intl)(n);i<nn;++i)
#define Rep1(i,n) for(intl i=1,nn=(intl)(n)+1;i<nn;++i)
#define vec vector
#define fi first
#define se second
#define eb emplace_back
#define SortA(v) sort(v.begin(), v.end())
#define SortD(v) sort(v.rbegin(),v.rend())
#define All(a) (a).begin(),(a).end()
#define Input(a) for(intl ii=0,nn=(intl)(a.size());ii<nn;ii++){cin>>(a).at(ii);}
#define Input2(a,b) for(intl ii=0,nn=(intl)(a.size());ii<nn;ii++){cin>>(a).at(ii);cin>>(b).at(ii);}
#define mp make_pair
using li = int64_t;
using intl = int64_t;
using vi = vec<intl>;
using vb = vec<bool>;
using vvi = vec<vi>;
using pi = pair<intl,intl>;
using vpi = vec<pi>;
using si = set<intl>;
using vsi = vec<si>;
using mii = map<intl,intl>;
using vmii = vec<mii>;
vec<intl> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vec<intl> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr intl INF = 9223372036854775807;


intl modpow(intl a, intl n, intl p){
  intl res = 1;
  while (n > 0){
    if (n&1){res = (res * a) % p;}
	a = (a * a) % p;
    n >>= 1;
  }
  return res;
}

intl modinv(intl a, intl p){
  if (a == 0){
    cout << "/0 at modinv"<<endl;
    exit(0);
  }
  if (a < 0){
    cout << "/- at modinv" <<endl;
    exit(0);
  }
  if (a==1){return 1;}
  if (a > p){return modinv(a%p, p);}

  return p - ( modinv(p%a,p) * (p/a) ) % p;
}

intl modcomb(intl n, intl k, intl p){
  if (k > n || k < 0 || n < 0){
    cout << "error at modcomb"<<endl;
    exit(0);
  }
  if (2*k > n){ k = n-k;}
  if (k ==0){return 1;}
  intl c=1;
  for (intl i = 0; i < k; i++){
    c =( c * ( (n-i) % p ) % p ) * modinv(i+1,p) % p;
  }
  return c;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  constexpr intl mod = 1000000007;


  li N;
  cin>>N;

  vi A(N);

  Input(A);

  li inv2=modinv(2,mod);
  li sum=0;
  li sumsq=0;



  for(auto a:A){
    sum +=a;
    sum %=mod;
    sumsq += a*a;
    sumsq %= mod;
  }

  sum *=sum;
  sum%=mod;

  sum -= sumsq;
  sum %= mod;
  
  sum *= inv2;

  sum %= mod;

  if(sum<0)sum+=mod;

  cout<<sum;

}