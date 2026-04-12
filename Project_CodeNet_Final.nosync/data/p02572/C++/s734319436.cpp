#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef unsigned long long ul ;
typedef long long ll ;
typedef string str ;
typedef pair <int, int >  pii ;
typedef pair <ll, ll>  pll ;
typedef vector <int> vi ;
typedef vector <bool> vb ;
typedef vector <ll> vll ;
typedef vector <pii> vpi ;
typedef vector <pll> vpl ;
#define umap unordered_map
#define endl '\n'

#define MOD 1000000007
#define vec vector
#define nl '\n' << flush
#define is ==
#define all(v) (v).begin() , (v).end()
#define revall(v) (v).rbegin() , (v).end() -1
#define sumof(v) accumulate(all(v), 0LL, plus<ll>())
#define maxof(v) max_element(all(v))
#define minof(v) min_element(all(v))
#define rev(v) reverse(all(v))
#define sz(v)  (long long)(v).size()
#define lp(i, n) for ( ll i = 0 ; i < (n) ; i++ )
#define lpd(i, n) for ( ll i = (n)-1 ; i >= 0 ; i-- )
#define lpc(it, c) for ( auto it = (c).begin(); it != (c).end(); it++)
#define lpv(val, c) for ( auto val : c )
#define lpr(i, l, r) for ( ll i = (l) ; i < (r) ; i++ )
#define lpdr(i, l, r) for ( ll i = (r)-1 ; i >= (l) ; i-- )

#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define inf INT_MAX
#define eps 1e-6
#define PI acos(-1)

#define tc(t) ul testcases ; cin >> testcases ; for(int testcase = 1 ; testcase <= testcases ; testcase++)
#define prntc cout << "Case #" << testcase << ": ";
#define printstl(c) for (auto it = (c).begin(); it != --((c).end()); it++) cout << *it << " "; cout << *(c.rbegin()) << "\n" << flush
#define printv(v, s, e) for(int i=(s); i<=(e); i++) cout<<(v)[i]<<" "; cout<<endl
#define print(v) cout << v << "\n" << flush
#define invec(vec_name, vec_size) vll vec_name(vec_size); lp(i,vec_size) cin >> vec_name[i];
#define printsp(x) cout<< x<< " "
#define fast ios::sync_with_stdio(false); cin.tie(0);

#ifndef ONLINE_JUDGE
#define show ; cerr <<
#define sp ; cerr << "\n";
#define debug(ds_name) for ( auto val : ds_name ) cerr<<val<<"\n" ; cerr<<"\n";
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__);
string sep = "-----------------------------\n";
#else
#define show ; {}
#define sp ; {} ;
#define debug(ds_name) {} ;
#define pr(...) {} ;
string sep = "" ;
#endif
template <class T> ostream &operator <<(ostream &os, const vector<T> &p) {os << "[ "; for (auto &it : p) os << it << " "; return os << "]"; } template <class T> ostream &operator <<(ostream &os, const unordered_set<T> &p) {os << "[ "; for (auto &it : p) os << it << " "; return os << "]"; } template <class T> ostream &operator <<(ostream &os, const set<T> &p) {os << "[ "; for (auto &it : p) os << it << " "; return os << "]"; } template <class T> ostream &operator <<(ostream &os, const multiset<T> &p) {os << "[ "; for (auto &it : p) os << it << " "; return os << "]"; } template <class S, class T> ostream &operator <<(ostream &os, const pair<S, T> &p) {return os << "(" << p.first << ", " << p.second << ")"; } template <class S, class T> ostream &operator <<(ostream &os, const unordered_map<S, T> &p) {os << "[ "; for (auto &it : p) os << it << " "; return os << "]"; } template <class S, class T> ostream &operator <<(ostream &os, const map<S, T> &p) {os << "[ "; for (auto &it : p) os << it << " "; return os << "]"; } template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n"; } template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...); } template <class T> T mx(T t) {return t; } template <class T, class... S> T mx(T t, S... s) {T tt = mx(s...); return (t) > (tt) ? (t) : (tt); } template <class T> T mn(T t) {return t; } template <class T, class... S> T mn(T t, S... s) {T tt = mn(s...); return (t) < (tt) ? (t) : (tt); } template <class T, class Op> T acc(Op op, T t) {return t; } template <class T, class Op, class... S> T acc(Op op, T t, S... s) {return op(t, acc(op, s...)); } template <class D1, class D2> auto lambdamax() {return [](D1 a, D2 b) {return (a) > (b) ? (a) : (b) ; } ; } template <class D1, class D2> auto lambdamin() {return [](D1 a, D2 b) {return (a) < (b) ? (a) : (b) ; } ; } ll modExp(ll x, ll y, ll mod) {x %= mod, y %= (mod - 1) ; ll res = 1; while (y) {if (y & 1) res = (res * x) % mod; y /= 2, x = (x * x) % mod; } return res % mod; }
int cel(int num, int den)
{
    if(num%den==0) return num/den;
    else return 1+num/den;
}

class SegTree {public: SegTree *lchild, *rchild; int leftmost, rightmost; int sum; int lazy=0; SegTree(int leftmost, int rightmost, vector<int>& v) {this->leftmost = leftmost; this->rightmost = rightmost; if(leftmost==rightmost) {sum = v[leftmost]; return; } int mid = (leftmost+rightmost)/2; lchild = new SegTree(leftmost, mid, v); rchild = new SegTree(mid+1, rightmost, v); recalc(); } void recalc() {if(leftmost==rightmost) return ; sum = lchild->sum + rchild->sum; } void pointUpdate(int index, int val) {updateLazy(); if(leftmost==rightmost){sum+=val; return; } int mid = (leftmost+rightmost)/2; if(index<=mid) lchild->pointUpdate(index, val); else rchild->pointUpdate(index, val); recalc(); } bool leaf() {return leftmost==rightmost; } void updateLazy() {if(this->lazy!=0){this->sum += lazy*(rightmost-leftmost+1); if(!leaf()) {lchild->lazy+= lazy; rchild->lazy+= lazy; } lazy=0; } } void rangeUpdate(int left, int right, int val) {updateLazy(); if(right<leftmost or left> rightmost) return; if(right>=rightmost and leftmost>=left){sum+= val*(rightmost-leftmost+1); if(!leaf()) {lchild->lazy+= val; rchild->lazy+= val; } return; } lchild->rangeUpdate(left, right, val); rchild->rangeUpdate(left, right, val); recalc(); return; } int rangeSum(int left, int right) {updateLazy(); if(right<leftmost or left>rightmost) return 0; if(right>=rightmost and left<=leftmost) return sum; return lchild->rangeSum(left, right)+rchild->rangeSum(left, right); } };
void inorder(SegTree* root) {if(root==NULL) return ; inorder(root->lchild); inorder(root->rchild); cout<<root->sum<<" "<<root->lazy<<"     "<<root->leftmost<<" "<<root->rightmost<<endl; }
inline void get(vector<int> &arr, int n) {int a; for (int i = 0; i < n; i++) {cin >> a; arr.push_back(a); } }



int32_t main()
{
    fast
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
    #endif
    int mod = 1e9+7;
    int n;
    cin>>n;
    invec(v,n);
    int sum = sumof(v);
    int a = ((sum%mod)*(sum%mod))%mod;
    int b=0;
    for(int i=0; i<n; i++)
    {
        b= (b%mod + (modExp(v[i],2, mod ))%mod)%mod;
    }

    int ans = (a-b+mod)%mod;
    ans = (ans*(500000004)%mod)%mod;
    cout<<ans<<endl;
    
}
