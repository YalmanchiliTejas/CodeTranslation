#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define pb push_back
#define sz(i) (int)(i.size())
#define F first
#define S second
#define LL long double
#define P pair<int, int>
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = (int)1e9 + 7;
using namespace std;
#ifndef ONLINE_JUDGE
#define tr(...) {__l(__LINE__);__f(#__VA_ARGS__, __VA_ARGS__);}
inline void __l(int line) { cerr << "#" << line << ": "; }template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args){const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);}
#else
#define tr(...)
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}template<typename T>inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v){bool first = true;os << "[";for(auto i: v){if(!first)os << ", ";os << i;first = false;}return os << "]";}
const int N = 2*(int)1e5 + 10;
// make sure N size is correctttt!!!!!!!!!

//Segment tree operations: Range update(Lazy propagation) and Range Query

const int MAX = 2e5 + 5;
const int LIM = 7.5*1e5 + 5;        //equals 2 * 2^ceil(log2(n))

int a[MAX];
int seg[LIM];
int lazy[LIM];
bool push[LIM];

//Complexity: O(1)
//Stores what info. segment[i..j] should store
int combine(int &a, int &b) {
   return max(a, b);
}

//Lazy propagation
void propagate(int t, int i, int j) {
   if (push[t]) {
      seg[t] = seg[t] + lazy[t];
      if (i != j) {
         push[t*2] = true;
         push[t*2 + 1] = true;
         lazy[t*2] = lazy[t*2] + lazy[t];
         lazy[t*2 + 1] = lazy[t*2 + 1] + lazy[t];
      }
      push[t] = false;
      lazy[t] = 0;
   }
}

//Complexity: O(n)
void build(int t, int i, int j) {
   push[t] = false;
   lazy[t] = 0;
   if (i == j) {
      //base case : leaf node information to be stored here
      seg[t] = a[i];
      return ;
   }
   int mid = (i + j) / 2;
   build(t*2, i, mid);
   build(t*2 + 1, mid + 1, j);
   seg[t] = combine(seg[2*t], seg[2*t+1]);
}

//Complexity: O(log n)
void update(int t, int i, int j, int l, int r, int x) {
   propagate(t, i, j);
   if (i > r || j < l) {
      return ;
   }
   if (l <= i && j <= r) {
      //base case : leaf node information to be stored here
      lazy[t] += x;
      push[t] = true;
      propagate(t, i, j);
      return ;
   }
   int mid = (i + j) / 2;
   update(t*2, i, mid, l, r, x);
   update(t*2 + 1, mid + 1, j, l, r, x);
   seg[t] = combine(seg[2*t], seg[2*t+1]);
}

//Complexity: O(log n)
int query(int t, int i, int j, int l, int r) {
   propagate(t, i, j);
   if (i > r || j < l) {
      //base case: result of out-of-bound query
      return 0;
   }
   if (l <= i && j <= r) {
      return seg[t];
   }
   int mid = (i + j) / 2;
   if (l <= mid) {
      if (r <= mid) {
         return query(t*2, i, mid, l, r);
      }
      else {
         int a = query(t*2, i, mid, l, r);
         int b = query(t*2 + 1,  mid + 1, j, l, r);
         return combine(a, b);
      }
   }
   else {
      return query(t*2 + 1,  mid + 1, j, l, r);
   }
}

int n, m, dp[N];
vector<P> L[N], R[N];

int32_t main(){_
   cin>>n>>m;

   for (int i = 0; i < m; ++i)
   {
      int l, r, x;
      cin>>l>>r>>x;
      L[l].pb({l-1, x});
      R[r].pb({l-1, x});
   }

   // void update(int t, int i, int j, int l, int r, int x) {
   // int query(int t, int i, int j, int l, int r) {

   int ans = 0;
   for (int i = 1; i <= n; ++i)
   {
      for(auto it: L[i])
         update(1, 0, n, 0, it.F, it.S);

      int tmp_ans = query(1, 0, n, 0, i-1);
      smax(ans, tmp_ans);
      update(1, 0, n, i, i, tmp_ans);

      for(auto it: R[i])
         update(1, 0, n, 0, it.F, -it.S);
   }

   cout<<ans;
   //make sure N size is correct!!!!!!!!!
   return 0;
}