#include <bits/stdc++.h>
using namespace std;

#define int long long
struct A{int l,r,a;};
typedef pair<int,int> P;
//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  //この辺はとりあえずbeetのブログ読むのが良さそう？
  //最初の具体例で言うとTとEが0以上の整数で、F(a,b):max(a,b) G(a,α):if(α)a=α H(α,β):if(β)α=β のはず
  int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  vector<int> leng;
  SegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}


  /*
  イメージ的には
  initとbuildは初期化　buildだとvectorで初期化出来る
  reflectは作用済のdatを返すので適切なdatとlazが入っていればいい
  propagateはkの作用をeiにリセットする役割で、作用を全部済ませる（datの更新と子のlazへの渡し）
  thrustは（vectorでの）kを渡すとkの列を上から順にpropagateすることで上のlazを空にする
  recalcは（vectorでの）kを渡すとkの列を下から順にdatを子のdatのクエリ済のものに更新する（自分のlazは適用しない）
  updateは（vectorでの）a,b,xを渡すと[a,b)に作用xを適用
  　　　　　まず閉区間で区間の端二列に関してはlazを一回空にしておく
  　　　　　区間をカバーする最小個のブロックのlazを更新する
          そのあと閉区間で端っこに関してはdatを変更していく
  set_valは要素一つに値一つを代入する
  　　　　　その列のlazを空にしてから一番下に代入して、上にどんどんdatを更新
  queryは普通にやるだけなんだけど、なんでこれで良いかを考える必要がありそう
  一番引っかかったのはqueryやupdateで両端だけthrustやrecalcをするか
  例えば[a,b]にupdateやったあとに[c,d]に対してqueryをする時に[c,d]で見るノードは
  1.[a,b]でアプデしたノード
  2.[a,b]に関係ないノード
  3.a,b,c,dいずれかの上にあるノード
  だけってのが成り立つからっぽい気がする
  */

  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
    leng.resize(2*n);
    int tmp=n;
    for(int j=1;j<2*n;j*=2){
      for(int i=j;i<2*j;i++)leng[i]=tmp;
      tmp/=2;
    }
  }

  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  //inlineは実行時間が短くなる魔法なので読む時には気にしなくていいはず

  inline T reflect(int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);//作用済のdat[k]の値を返す
  }

  //propagateは伝わるって意味らしい
  inline void propagate(int k){//laz[k]をdat[k]と子のlazに適用して自身をeiに戻す
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);//子の作用の更新
    dat[k]=reflect(k);//dat[k]を作用済に変更
    laz[k]=ei;//作用したのでlaz[k]はリセット
  }

  //thrustは突き出すって意味らしい
  inline void thrust(int k){
    for(int i=height;i;i--) propagate(k>>i);//kの列を一番上から更新させていく 子がいない一番下にはやらない
  }

  inline void recalc(int k){
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));//kの列を下から上に更新していく
  }

  void update(int a,int b,E x){//[a,b)に作用Eを適用
    thrust(a+=n);//aを一番下のそれにして、その列の一番上から現在溜まっている作用を済ませておく
    thrust(b+=n-1);//bについても同様　ただしここでbは閉区間としてのそれになっている
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){//[a,b)の範囲を一番カバーできるlaz(だいたいlog個)を更新する
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);//今回作用を施した端っこについて下から上にdatを更新していく
    recalc(b);
  }

  void set_val(int a,T x){//aにxを代入
    thrust(a+=n);//aを一番下のそれにして、その列の一番上から現在溜まっている作用を済ませておく
    dat[a]=x;laz[a]=ei;//aの値をxに変更してそこのlazをリセット
    recalc(a);//aの上のdatを更新
  }

  T query(int a,int b){//[a,b)のfを求めるいつものクエリ
    thrust(a+=n);//aを一番下のそれにして、その列の一番上から現在溜まっている作用を済ませておく
    thrust(b+=n-1);//bを一番下のそれにして、その列の一番上から現在溜まっている作用を済ませておく
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,reflect(k));
      return check(acc)?k-n:-1;
    }
    propagate(k);
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }

  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
};
//END CUT HERE
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}
const long long LINF=1e18;

signed main(){
  int n,m;cin>>n>>m;
  vector<A> s(m);
  for(int i=0;i<m;i++){
    int l,r,a;cin>>l>>r>>a;
    s[i]={l,r,a};
  }
  vector<int> L(234567,0);
  vector<P> R[234567];
  for(int i=0;i<m;i++){
    L[s[i].l]+=s[i].a;
    R[s[i].r].push_back(P(s[i].l,s[i].a));
  }
  auto f=[](int a,int b){return max(a,b);};
  auto g=[](int a,int b){return a+b;};
  SegmentTree<int,int> seg(f,g,g,-LINF,0);
  seg.init(n+5);
  seg.set_val(0,0);
  int ans=0,now=0;
  for(int i=1;i<=n;i++){
    seg.update(0,i,L[i]);
    int S=seg.query(0,i);
    seg.set_val(i,S);
    chmax(ans,S);
    for(P p:R[i]){
      int l=p.first,a=p.second;
      seg.update(0,l,-a);
    }
  }
  cout<<ans<<endl;
}
