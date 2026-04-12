#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define mod1 998244353
#define lli long long int
#define plli pair<lli,lli>
#define REP(i,a,b) for(lli i=a;i<b;i++)
#define REPI(i,a,b) for(lli i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
typedef vector<plli> vii; // three data type shortcuts. They may look cryptic
typedef vector<lli> vi;

#define o_set tree<int, nulli_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setlli tree<lli, nulli_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
 
lli modI(lli a, lli m);
lli gcd(lli a, lli b);
lli powM(lli x, unsigned lli y, unsigned lli m);
void pairsort(int a[], int b[], int n);
void pairsortlli(lli a[],lli b[],lli n);
lli logint(lli x,lli y);
void Miden(lli **p1,lli n);
void Mmult(lli **p1,lli **p2,lli **ans,lli x,lli y,lli z,lli m);
void Mpow(lli **p1,lli **ans,lli n,lli y,lli m);
plli Egcd(lli x,lli y);
#define LSOne(S) (S & (-S))

class SegmentTree {         // the segment tree is stored like a heap array
private: vector<lli> st;
string A;            // recall that vi is: typedef vector<int> vi;
  lli n;
  lli left (lli p) { return (p << 1)+1; }     // same as binary heap operations
  lli right(lli p) { return (p << 1) + 2; }

  void build(lli p, lli L, lli R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = 1;                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      lli p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  } }

  lli rmq(lli p, lli L, lli R, lli i, lli j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    lli p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    lli p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;                               // same as above
    return (A[p1] <= A[p2]) ? p1 : p2; }          // as as in build routine

  lli update_point(lli p, lli L, lli R, lli idx, lli new_value) {
    // this update code is still preliminary, i == j
    // must be able to update range in the future!
    lli i = idx, j = idx;

    // if the current interval does not intersect 
    // the update interval, return this st node value!
    if (i > R || j < L)
      return st[p];

    // if the current interval is included in the update range,
    // update that st[node]
    if (L == i && R == j) {
      A[i] = new_value; // update the underlying array
      return st[p] = L; // this index
    }

    // compute the minimum position in the 
    // left and right part of the interval
    lli p1, p2;
    p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

    // return the position where the overall minimum is
    return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }

public:
  SegmentTree(string _A) {
    A = _A; n = (lli)A.length();              // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    build(0, 0, n - 1);                                  // recursive build
  }

  lli rmq(lli i, lli j) { return rmq(0, 0, n - 1, i, j); }   // overloading

  lli update_point(lli idx, lli new_value) {
    return update_point(0, 0, n - 1, idx, new_value); }
};
  
class FenwickTree {
private:
  vector<lli> ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(lli n) { ft.assign(n + 1, 0); }

  lli rsq(lli b) {                                     // returns RSQ(1, b)
    lli sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  lli rsq(lli a, lli b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(lli k, lli v) {                    // note: n = ft.size() - 1
    for (; k < (lli)ft.size(); k += LSOne(k)) ft[k] += v; }
};

class UnionFind {                                              // OOP style
public:
  vector<lli> p, rank, setSize;                       // remember: vi is vector<int>
  lli numSets;
  UnionFind(lli N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (lli i = 0; i < N; i++) p[i] = i; }
  lli findSet(lli i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(lli i, lli j) { return findSet(i) == findSet(j); }
  void unionSet(lli i, lli j) { 
    if (!isSameSet(i, j)) { numSets--; 
    lli x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  lli numDisjointSets() { return numSets; }
  lli sizeOfSet(lli i) { return setSize[findSet(i)]; }
};

lli gcd(lli x,lli y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
 
plli Egcd(lli x,lli y)
{
    if(x==0) return MP(0,1);
    plli t=Egcd(y%x,x);
    return MP(t.S-t.F*(y/x),t.F);
}
 
lli pow(lli x,lli y,lli m)
{
    if(y==0) return 1;
    lli p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
 
lli modI(lli a, lli m)
{
    lli m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        lli q=a/m;
        lli t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}
 
void pairsort(int a[],int b[],int n)
{
    pair<int,int> v[n];
    REP(i,0,n)
    {
        v[i].F=a[i];
        v[i].S=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].F;
        b[i]=v[i].S;
    }
}
 
void pairsortlli(lli a[],lli b[],lli n)
{
    pair<lli,lli> v[n];
    REP(i,0,n)
    {
        v[i].F=a[i];
        v[i].S=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].F;
        b[i]=v[i].S;
    }
}
 
lli logint(lli x,lli y)
{
    lli ans=0;
    lli a=1;
    for(lli i=0;i<=x;i++)
    {
        if(x<a)
        {
            return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}
 
void Miden(lli **p1,lli n)
{
    lli (*x)[n]=(lli(*)[n]) p1;
    REP(i,0,n)
    {
        REP(j,0,n)
        {
            x[i][j]=0;
        }
        x[i][i]=1;
    }
    return;
}
 
void Mmult(lli **p1,lli **p2,lli **ans,lli x,lli y,lli z,lli m)
{
    lli (*a)[y]=(lli (*)[y])p1;
    lli (*b)[z]=(lli (*)[z])p2;
    lli (*c)[z]=(lli (*)[z])ans;
    REP(i,0,x)
    {
        REP(j,0,z)
        {
            c[i][j]=0;
            REP(k,0,y)
            {
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=m;
            }
        }
    }
    return;
}
 
void Mpow(lli **p1,lli **ans,lli n,lli y,lli m)
{
    if(y==0)
    {
        Miden(ans,n);
        return;
    }
    lli t[n][n];
    Mpow(p1,(lli **)t,n,y/2,m);
    lli z[n][n];
    Mmult((lli **)t,(lli **)t,(lli **)z,n,n,n,m);
    if(y%2)
    {
        Mmult((lli **)z,p1,ans,n,n,n,m);
    }
    else
    {
        Miden((lli **)t,n);
        Mmult((lli **)z,(lli **)t,ans,n,n,n,m);
    }
    return;
}

 int main()
{
  lli n;
  cin>>n;
  lli a[n];
  lli dp[n][n];
  lli s=0;
  REP(i,0,n)
  {
    cin>>a[i];
    dp[i][i]=a[i];
    s+=a[i];
  }
  REP(i,1,n)
  dp[i-1][i]=max(a[i],a[i-1]);
  for(lli s=3;s<=n;s++)
  {
    for(lli i=0,j=i+s-1;j<n;j++,i++)
    {
      dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
    }
  }
  cout<<2*dp[0][n-1]-s<<endl;
}
