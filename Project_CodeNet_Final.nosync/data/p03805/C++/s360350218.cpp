#include "bits/stdc++.h"
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
void Printvector(std::vector<std::vector<T> > &a){
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
long long modinv(long long a, long long m) {//modの逆元
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}
struct c{
  ll a;
  ll b;
};
template<class T>
vector<T> getaccum(vector<T> a){
  int size=a.size();
  vector<T> ans(size);
  ans[0]=a[0];
  for(int i=0;i<size-1;i++){
    ans[i+1]=ans[i]+a[i+1];
    //ans[i+1]%=d9_7;
  }
  return ans;
}
// 比較関数を定義
bool cmp( const c& left, const c& right ) {
    return left.b>right.b;
}
template<class T>
/*

このBaseedgeクラスをなぜかクラスとして認識してくれない

*/
class Baseedge {
  public:
    int number;
    int v1;
    int v2;
    T length;
    T cost;
    Baseedge(int inputfrom , int inputto, T inputlength,T inputcost,int inputnumber){
      this->v1 = inputfrom;
      this->v2 = inputto;
      this->number = inputnumber;
      this->length = inputlength;
      this->cost = inputcost;
    }
    virtual int nextvertex(int from)=0;
};
template<class T>
class Uniedge : public Baseedge<T> {
  public:

    Uniedge(int inputfrom , int inputto, T inputlength,T inputcost,int inputnumber) : 
      Baseedge<T>(inputfrom,inputto,inputlength,inputcost, inputnumber){
        ;
      }
    
    int nextvertex(int from) override {
      return this->v2;
    }
};
template<class T>
class Biedge : public Baseedge<T> {
  public:

    Biedge(int inputfrom , int inputto, T inputlength,T inputcost,int inputnumber) : 
      Baseedge<T>(inputfrom,inputto,inputlength,inputcost, inputnumber){
        ;
      }
    int nextvertex(int from) override {
      if(this->v1==from){
        return this->v2;
      }else if(this->v2==from){
        return this->v1;
      }else{
        printf("ERROR Invalid number \n");
        return -1;
      }
    }
};
template<class T>
class graph {
  public:
  int n;//ノード数
  
  vector<Baseedge<ll>* > es;
  struct vertex{
    int number;
    set<int> edges;
  };
  vector<vertex> vs;
  //constructor
  graph(int input){
    n=input;
    vs=vector<vertex>(n);
    for(int i=0;i<n;i++){
      vs[i].number=i;
    }
  }
  void bind_uni(int from,int to,T len,T cost){
    //1方向につなぐ
    int num=es.size();
    Baseedge<T>* newedge = new Uniedge<T>(from,to,len,cost,num);
    es.push_back(newedge);
    vs[from].edges.insert(num);
  }
  void bind_bi(int v1,int v2,T len,T cost){
    //1方向につなぐ
    int num=es.size();
    Baseedge<T>* newedge = new Biedge<T>(v1,v2,len,cost,num);
    es.push_back(newedge);
    vs[v1].edges.insert(num);
    vs[v2].edges.insert(num);
  }
  int ans=0;
  void DFS(int now,T length,T cost,set<int> past,int pre=-1){
    if(past.find(now)!=past.end())return;
    past.insert(now);
    if(past.size()==n){
      ans++;
      return ;
    }
    for(auto i:vs[now].edges){
      int next=es[i]->nextvertex(now);
      if(next==pre)continue;
      DFS(next,length+es[i]->length,cost+es[i]->cost,past,now);
    }
  }
  void BFS(int ini){
    struct opera{
      int now;
      int pre;
      T len;
      T cost;
    };
    queue<opera> opes;
    opes.push_back({ini,-1,0,0});
    while(opes.size()>0){
      int now=opes.front().now;
      int pre = opes.front().pre;
      T len = opes.front().len;
      T cost = opes.front().cost;
      for(auto i:vs[i].edges){
        int next=es[i]->nextvertex(now);
        if(next==pre)continue;
        opes.push_back({next,now,len+es[i]->length,cost+es[i]->cost});
      }
      opes.pop_front();
    }
  }
};
int main(void){
  int n;
  cin>>n;
  graph<ll> G(n);
  int m;
  cin>>m;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.bind_bi(a,b,1,1);
  }
  G.DFS(0,0,0,{},-1);
  cout<<G.ans<<endl;
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
