#include <bits/stdc++.h>

using namespace std;

struct T;
#define null ((T*)NULL)

typedef long long ll;

struct T {
  ll v;
  ll s;
  ll m;
  int c;
  T *l,*r;
  bool lz;
  ll lazy;
  T(){}
  T(ll v):v(v),s(v),m(v),c(1),l(null),r(null),lz(false),lazy(0){}
};

int hogeS=0;
#define SSS 2222222
T hoge[SSS];
inline T* New(int v){
  if(hogeS >= SSS) exit(-1);
  hoge[hogeS]=T(v);
  return &hoge[hogeS++];
}
inline int count(T* t){ return t?t->c:0; }
inline void push(T* t)
{
  if( !t ) return;
  if( t->lz ) {
    t->v += t->lazy;
    t->m += t->lazy;
    t->s += t->lazy*count(t);
    t->lz = false;
    if( t->r ) {
      t->r->lz |= true;
      t->r->lazy += t->lazy;
    }
    if( t->l ) {
      t->l->lz |= true;
      t->l->lazy += t->lazy;
    }
    t->lazy = 0;
  }
}
inline ll sum(T* t){ push(t); return t?t->s:0; }
inline ll mini(T* t){ push(t); return t?t->m:LLONG_MAX; }

inline T* update(T* t)
{
  if(!t)return t;
  push(t);
  t->c = count(t->l)+count(t->r)+1;
  t->s = t->v+sum(t->l)+sum(t->r);
  t->m = min(t->v,min(mini(t->l),mini(t->r)));
  return t;
}

T* merge(T* a,T* b)
{
  push(a);
  push(b);
  if(!a || !b)return a?a:b;
  if(rand()%(count(a)+count(b))<count(a)){
    a->r = merge(a->r,b);
    return update(a);
  } else {
    b->l = merge(a,b->l);
    return update(b);
  }
}

pair<T*,T*> split(T* a,int k)
{
  push(a);
  if(!a)return make_pair(null,null);
  if(k<=count(a->l)){
    pair<T*,T*> s=split(a->l,k);
    a->l = s.second;
    return make_pair(s.first,update(a));
  } else {
    pair<T*,T*> s=split(a->r,k-count(a->l)-1);
    a->r = s.first;
    return make_pair(update(a),s.second);
  }
}

inline T* erase(T* t,int k)
{
  push(t);
  pair<T*,T*> v = split(t,k);
  k -= (k-1);
  pair<T*,T*> u = split(v.second,k);
  return merge(v.first,u.second);
}

inline T* insert(T* t,int k,int v)
{
  push(t);
  pair<T*,T*> a=split(t,k);
  return merge(merge(a.first,New(v)),a.second);
}

inline T* add(T* t,int l,int r,int k)
{
  push(t);
  pair<T*,T*> u = split(t,r);
  pair<T*,T*> v = split(u.first,l);
  T* w = v.second;
  w->lz = true;
  w->lazy += k;
  return merge(merge(v.first,update(w)),u.second);
}

inline T* add(T* t,int k)
{
  push(t);
  t->lz |= true;
  t->lazy += k;
  return update(t);
}

int n,m;
char s[333333];
inline T* flip(T* t,int k)
{
  push(t);
  pair<T*,T*> a=split(t,k);
  pair<T*,T*> b=split(a.second,1);
  //b.first->v = -b.first->v;
  //b.first = add(b.first,k,n);
  return merge(a.first,merge(b.first,b.second));
}

void print(T* t)
{
  if(t==null)return;
  push(t);
  print(t->l);
  printf("%2lld,%2lld|",t->v,t->m);
  print(t->r);
}

inline int gsum(T* t)
{
  /*
  if( !t->r ) return t->v;
  return gsum(t->r);
  */
  return 0;
}

int main(void)
{
  T *root = null;
  int n,q,m;
  set<int> toji;
  scanf("%d%d",&n,&q);
  scanf("%s",s);
  for( int i = 0; i < n; i++ ) {
    root = insert(root,i,0);
  }
  for( int i = 0; i < n; i++ ) {
    root = add(root,i,n,s[i]=='('?1:-1);
    if( s[i] == ')' ) toji.insert(i);
  }
  //print(root); puts("");
  int k;
  for( int ii = 0; ii < q; ii++ ) {
    scanf("%d",&k);
    //printf("%d %d\n",mini(t),gsum(t));
    //print(t); puts("");
    if( s[k-1] == '(' ) {
      s[k-1] = ')';
      toji.insert(k-1);
      root = add(root,k-1,n,-2);
      int me = *(toji.begin());
      printf("%d\n",me+1);
      s[me] = '(';
      toji.erase(me);
      root = add(root,me,n,2);
    } else {
      toji.erase(k-1);
      s[k-1] = '(';
      root = add(root,k-1,n,2);
      int l=0,r=n;
      while( l < r ) {
        //printf("%d %d\n",l,r);
        int mb = (l+r)/2;
        auto t = split(root,mb);
        if( mini(t.second) >= 2 ) {
          r = mb;
        } else {
          l = mb+1;
        }
        root = merge(t.first,t.second);
      }
      printf("%d\n",l+1);
      s[l] = ')';
      toji.insert(l);
      //printf(":%d %d\n",l,r);
      root = add(root,l,n,-2);
    }
    //puts(s);
    //printf("%d\n",kakko);
    //print(root); puts("");
    /*
      printf("sum:%d min:%d\n",gsum(t),mini(t));
    //*/
  }
  return 0;
}