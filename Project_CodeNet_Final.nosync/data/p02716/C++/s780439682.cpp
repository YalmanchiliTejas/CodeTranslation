#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <unordered_set>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double
#define Sort(a) sort(a.begin(),a.end())
#define cSort(a,cmp) sort(a.begin(),a.end(),cmp)
#define reSort(a) sort(a.rbegin(), a.rend())
static const ll llMAX = numeric_limits<long long>::max();
static const int intMAX = numeric_limits<int>::max();
static const ll  llMIN = numeric_limits<long long>::min();
static const int intMIN = numeric_limits<int>::min();
static const ll d_5 = 100000;
static const ll d9_7 = 1000000007;
static const ll d_9 = 1000000000;
static const double PI=3.14159265358979323846;
template<class T>
T gcd(T a,T b){
  if(a==0){
    return b;

  }else if(b==0){
    return a;
  }
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}
ll digitpower(ll a,ll b){//aのb乗を計算
  if(b==1){
    return a;
  }else if(b==0){
    return 1;
  }
  int mode=0;
  if(mode==0){
    if(b%2==1){
      ll tmp = digitpower(a,(b-1)/2);
      tmp%=d9_7;
      tmp*=tmp;
      tmp%=d9_7;
      tmp*=a;
      return (tmp)%d9_7;
    }else{
      ll tmp = digitpower(a,(b)/2);
      tmp%=d9_7;
      tmp*=tmp;
      tmp%=d9_7;
      return (tmp)%d9_7;
    }
  }else{
    if(b%2==1){
      ll tmp = digitpower(a,(b-1)/2);
      tmp*=tmp;
      tmp*=a;
      return (tmp);
    }else{
      ll tmp = digitpower(a,(b)/2);
      tmp*=tmp;
      return (tmp);
    }
  }
  return 0;
  
}
template<class T>
void Printvector(std::vector<T> &a){
  int size = a.size();
  rep(i,size){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
template<class T>
void Printvector(std::vector<std::vector<T>> &a){
  int size = a.size();
  rep(i,size){
    int size2=a[i].size();
    rep(j,size2){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
unordered_set<ll> primes(ll n){
  unordered_set<ll> ret;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      ret.insert(i);
      ret.insert(n/i);
    }
  }
  return ret;
}
int main(void){
  ll n;
  cin>>n;
  vl a(n);
  rep(i,n)cin>>a[i];
  if(n%2==0){
    vl a1(n/2,0);
    vl a2(n/2,0);
    a2[0]=a[1];
    a1[0]=a[0];
    for(int i=2;i<n;i+=2){
      a1[i/2]=a1[i/2 -1]+a[i];
      a2[i/2]=a2[i/2 -1]+a[i+1];
    }
    ll ans=a2[n/2-1];
    for(int i=0;i<n/2;i++){
      ans=max(ans,a1[i]+a2[n/2-1]-a2[i]);
    }
    cout<<ans<<endl;
    return 0;
  }
  ll ans1=0,ans2=0;
  rep(i,(n-1)/2){
    ans1+=a[i*2];
    ans2+=a[i*2+1];
  }
  vector<vll> dp((n-1)/2,vll(2,vl(2,llMIN+1000)));
  //0は左、1が右
  //0がまだ空白やってない、1がもうやった
  dp[0][0][0]=a[0];
  dp[0][1][0]=a[1];
  dp[0][0][1]=0;
  dp[0][1][1]=0;

  rep(i,(n-1)/2-1){
    dp[i+1][0][0]=dp[i][0][0]+a[(i+1)*2];
    dp[i+1][1][0]=max(dp[i][1][0]+a[(i+1)*2+1],dp[i][0][0]+a[(i+1)*2+1]);

    dp[i+1][0][1]=max(dp[i][0][0],dp[i][1][0]);
   // dp[i+1][1][1]=max(dp[i][0][0],dp[i][1][0]);

    dp[i+1][0][1]=max(dp[i+1][0][1],dp[i][0][1]+a[(i+1)*2]);
   // dp[i+1][1][1]=max(dp[i+1][1][1],dp[i][0][1]+a[(i+1)*2+1]);
   // dp[i+1][1][1]=max(dp[i+1][1][1],dp[i][1][1]+a[(i+1)*2+1]);
  }
  //ll ans3=a[n-1]+dp[(n-1)/2-1][0][0];
  ll ans4=a[n-1]+dp[(n-1)/2-1][0][1];
  ll ans=max({ans1,ans2,ans4});
  //ans=max(ans,ans3);
  cout<<ans<<endl;
  return 0;
}

//clang++ -g -fsanitize=address -fno-omit-frame-pointer 1.cpp -o test.exe

//<<std::setprecision(30)

//重複削除
 /* std::sort(vec.begin(), vec.end());
 
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());*/

  //ペアの全探索
  /*do{
		int s=0;
		for(int i=0;i<n/2;i++)s+=v[i]^v[i+n/2];
		r=max(s,r);
		reverse(v.begin()+n/2,v.end());
	}while(next_permutation(v.begin(),v.end()));*/
