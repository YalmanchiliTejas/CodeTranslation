#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define sz size()
#define bgn begin()
#define en end()
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define pri priority_queue
#define Pri priority_queue<int,vector<int>,greater<int>>
#define PriP priority_queue<P<int,int>,vector<P<int,int>>,greater<P<int,int>>>
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define all(a)  (a).begin(),(a).end()
#define elif else if
int low(V<int> &a,int b){
  auto c=lower_bound(a.begin(),a.end(),b);
  int d=c-a.bgn;
  return d;
}
int upp(V<int> &a,int b){
  auto c=upper_bound(a.begin(),a.end(),b);
  int d=c-a.bgn;
  return d;
}
template<class T>
 void cou(vector<vector<T>> a){
  int b=a.size();
  int c=a[0].size();
  fo(i,b){
    fo(j,c){
      cout<<a[i][j];
      if(j==c-1)
        cout<<endl;
      else
        cout<<' ';
    }
  }
}
int wari(int a,int b) {
  if(a%b==0)
    return a/b;
  else
    return a/b+1;
}
int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
}
int souwa(int a){
  return a*(a+1)/2;
}
int gcm(int a,int b){
  if(a%b==0)
    return b;
  return gcm(b,a%b);
}
bool prime(int a){
  if(a<2)
    return false;
  else if(a==2)
    return true;
  else if(a%2==0)
    return false;
  for(int i=3;i<=sqrt(a)+1;i+=2){
    if (a%i==0)
      return false;
  }
  return true;
}
struct Union{
  vector<int> par;
  Union(int a){
  par=vector<int>(a,-1);
  }
  int find(int a){
    if(par[a]<0)
      return a;
    else
      return par[a]=find(par[a]);
  }
  bool same(int a,int b){
    return find(a)==find(b);
  }
  int Size(int a){
    return -par[find(a)];
  }
  void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)
      return;
    if(Size(b)>Size(a))
      swap<int>(a,b);
    par[a]+=par[b];
    par[b]=a;
  }
};
int ketas(int a){
  string b=to_string(a);
  int c=0;
  fo(i,keta(a)){
    c+=b[i]-'0';
  }
  return c;
}
bool fe(int a,int b){
  a%=10;
  b%=10;
  if(a==0)
    a=10;
  if(b==0)
    b=10;
  if(a>b)
    return true;
  else
    return false;
}
int INF=1000000007;
struct edge{int s,t,d; };
V<int> mojisyu(string a){
  V<int> b(26,0);
  fo(i,a.sz){
    b[a[i]-'a']++;
  }
  return b;
}
int wa2(int a){
  if(a%2==1)
    return a/2;
  return a/2-1;
}
int kaijou(int a){
  int b=1;
  fo(i,a)
    b*=i+1;
  return b;
}
long long modpow(long long a,long long n,long long mod) {
    long long res=1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

int lcm(int a,int b){
  int c=modinv(gcm(a,b),INF);
  return ((a*c)%INF)*(b%INF)%INF;
}
int lcm_kai(int a,int b){
    if(a<b) swap(a,b);
    int n=a,m=b;
    while(a%b!=0){
        int t=b;
        b=a%b;
        a=t;
    }
    return n/b*m;
}
int MOD=INF;
int fac[1000010], finv[1000010], inv[1000010]; 

void COMinit() {
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<1000010;i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
// 二項係数計算
int COM(int n,int k){
  if(n<k)
    return 0;
  if(n<0||k<0)
    return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int pow_kai(int a, int b){
  int c=1;
  while(b>0){//bit全部捨てるまで
    if(b%2){//一番右のbitが1
      c=c*a;
    }
    a=a*a;
    b>>=1;//全体右に1つシフト
  }
  return c;
}
//12だったら{(2,2),(3,1)}って返してくれるはず
V<P<int,int>> factorize(int n){
  V<P<int,int>> res;
  for(int i=2; i*i<=n; i++){
    if(n%i)
      continue;
    res.emplace_back(i,0);
    while(n%i==0){
      n/=i;
      res.back().second++;
    }
  }
  if(n!=1)
    res.emplace_back(n,1);
  return res;
}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

signed main(){
  int h , w;
  cin >> h >> w;
  V<string> a(h);
  fo(i , h){
    cin>>a[i];
  }
  V<bool> row(h , 0);
  V<bool> col(w , 0);
  fo(i,h){
    fo(j,w){
      if(a[i][j]=='#'){
        row[i]=1;
        col[j]=1;
      }
    }
  }
  fo(i,h){
    if(row[i]){
      fo(j,w){
        if(col[j])
          cout<<a[i][j];
      }
    }
    cout<<endl;
  }
}