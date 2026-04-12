#include <bits/stdc++.h>  // ver2.3.0
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define COUNT(a,k) upper_bound(ALL(a),k)-lower_bound(ALL(a),k)
#define BIGGER(a,k) a.end()-upper_bound(ALL(a),k)
#define SMALLER(a,k) lower_bound(ALL(a),k)-a.begin()
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Pii pair<int,int>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl
#define _ <<' '<<
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define Vout(a) rep(lZ,0,a.size()-1)cout<<a[lZ]<<' ';cout<<a.back()<<endl
#define VVout(a) rep(lY,0,a.size()){if(!a[lY].empty()){Vout(a[lY]);}else cout<<endl;}
#define VPout(a) rep(lX,0,a.size())cout<<a[lX].FI<<' '<<a[lX].SE<<endl
#define Verr(a) rep(iZ,0,a.size()-1)cerr<<a[iZ]<<' ';cerr<<a.back()<<endl
#define VVerr(a) rep(J,0,a.size()){if(!a[J].empty()){Verr(a[J]);}else cerr<<'.'<<endl;}
#define VPerr(a) rep(iX,0,a.size())cerr<<a[iX].FI<<' '<<a[iX].SE<<endl
#define INF 3000000000000000000  //  3.0*10^18(MAXの1/3くらい)
#define MAX LLONG_MAX
#define PI 3.14159265358979
#define MOD 1000000007  //  10^9 + 7
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm
int mypow(int x, int n, int m){  //  累乗x^n(mod m)  O(log(n)) ※nはMOD環境の数値ダメ！
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int scomb(int n, int r){if((n-r)<r)r=n-r;  //  nCr (小さい場合)
int a=1;for(int i=n;i>n-r;--i){a=a*i;}for(int i=1;i<r+1;++i){a=a/i;}return a;}
int comb(int n, int r){if((n-r)<r)r=n-r;  //  nCr (%MOD)
int a=1;for(int i=n;i>n-r;--i){a=a*i%MOD;}for(int i=1;
i<r+1;++i){a=a*mypow(i,MOD-2,MOD)%MOD;}return a%MOD;}
int stpow(int n){  //  階乗(%MOD)
if(n==0)return 1;int a=1;rep(i,1,n+1)a=a*i%MOD;return a;}
Vi stpowV(){Vi a(100001);  //  階乗配列(%MOD)
a[0]=1;repeq(i,1,100000)a[i]=a[i-1]*i%MOD;return a;}
void press(auto &v){v.erase(unique(ALL(v)),v.end());}  //  圧縮


Vi zip(Vi b){
int Z=b.size();Pii p[Z+10];int a=b.size();Vi l(a);for(int i=0;i<a;i++)
p[i]=mp(b[i],i);sort(p,p+a);int w=0;for(int i=0;i<a;i++)
{if(i&&p[i].first!=p[i-1].first)w++;l[p[i].second]=w;}return l;}


int leaf(int n) {
  int a=1;
  while(a<n) a *= 2;
  return a;
}


struct PQ2 {
  
  /*使い方まとめ*/
  
  /*
  
  PQ2 myque(n)  //宣言 nは入るであろう最大のint以上
  myque.insert(k) //kを挿入
  myque.erase(k) //kを削除
  myque.count(k) //kの個数を返す
  myque.rank(i)  //i番目に小さい要素を返す(0-index)
  myque.rankr(i) //i番目に大きい要素を返す(0-index)
  myque.smaller(k) //kより小さい要素の最大のものを返す(なければ-1を返す)※テスト中
  myque.bigger(k) //kより大きい要素の最小のものを返す(なければ-1を返す)※テスト中
  
  ※※※　　2個以上同じものを入れたらバグる可能性あり(一応対策済)　　※※※
  ※※※　　負のintは入りません　　※※※
  */
  vector<int> value;
  
  PQ2(int n) : value(0) {
    int ct = leaf(n)*2-1;
    rep(i,0,ct) value.pb(0); // 全部0
  }
  
  void update(int i, int x) {
    int N = (value.size()+1)/2;
    i += N - 1;
    value[i] += x;
    while (i > 0) {
      i = (i - 1) / 2;
      value[i] = value[i * 2 + 1]+value[i * 2 + 2];
    }
    return;
  }
  
  int at(int i) { //i番目の要素にアクセス
    int N = (value.size()+1)/2;
    return value[i-1+N];
  }
  
  int count(int i) { //i番目の要素にアクセス
    int N = (value.size()+1)/2;
    return value[i-1+N];
  }
  
  int RSQ2(int a, int b, int k, int l, int r) {
    // [a, b) の区間に対するクエリについて
    // ノード k （区間 [l, r) 担当）が答える
    if (r <= a || b <= l) return 0; // 区間が被らない場合は0を返す
    if (a <= l && r <= b)
      return value[k]; // ノード k の担当範囲がクエリ区間 [a, b)に完全に含まれる
    else {
      int c1 = RSQ2(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
      int c2 = RSQ2(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
      return c1+c2; // 左右の子の値の sum を取る
    }
  }
  
  int rsum(int a,int b) {
    int N = (value.size()+1)/2;
    return RSQ2(a,b+1,0,0,N);
  }
  
  void insert(int a) {
    update(a,1);
    return;
  }
  
  int rank(int i) {
    i++;
    int L=0,R=(value.size()+1)/2-1;
    int mid = (L+R)/2;
    int eq,minus,ct=0;
    while(ct<300){
      eq = rsum(0,mid);
      minus = rsum(0,mid-1);
      
      if(eq == i && minus <= i-1) {
        break;
      }
      if(eq > i) {
        R = mid;
      }
      if(eq == i && minus == i) {
        R = mid;
      }
      if(eq < i) {
        L = mid;
      }
      mid = (L+R)/2;
      ct++;
    }
    if(ct==300) mid++;
    return mid;
  }
  
  int rankr(int i) {
    return rank(value[0]-1-i);
  }
  
  void erase(int a) {
    update(a,-1);
    return;
  }
  
  int smaller(int k) { // バグの可能性大
    int L=0,R=k-1;
    if(rsum(0,k-1)==0) return -1;
    int mid = (L+R)/2;
    while(L<R) {
      if(rsum(mid,R) == 0){
        R = mid-1;
      }
      else {
        L = mid;
      }
      mid = (L+R+1)/2;
    }
    return mid;
  }
  
  int bigger(int k) { // バグの可能性大
    int L=k+1,R=(value.size()+1)/2-1;
    if(rsum(L,R)==0) return -1;
    int mid = (L+R)/2;
    while(L<R) {
      if(rsum(L,mid) == 0){
        L = mid+1;
      }
      else {
        R = mid;
      }
      mid = (L+R)/2;
    }
    return mid;
  }
  
};

signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);
  int n;
  cin >> n;
  Vi a(n);
  Vin(a);
  a = zip(a);
  
  PQ2 myque(100010);
  int qw;
  
  rep(i,0,n){
    qw = myque.smaller(a[i]);
    if(qw == -1) myque.insert(a[i]);
    else {
      myque.erase(qw);
      myque.insert(a[i]);
    }
  }
  cout << myque.rsum(0,100005) << endl;
  return 0;
}