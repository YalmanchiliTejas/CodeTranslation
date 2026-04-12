#include <bits/stdc++.h>
using namespace std;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
typedef long long ll;
typedef long double ld;
#define debug(n) cerr << "[" << #n << " = " << n << "]" << '\n'
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, (b)<(e)?1:-1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define lp(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define each(a,x) for (auto& a: x)
#define pb push_back
#define ins insert
#define sz(v) (int) v.size()

ll FirstTrue (ll l,ll r,function<bool(ll)>f) {
    while(l<r){
    ll mid=l+(r-l)/2;
    f(mid)?r=mid:l=mid+1; } 
    return l;
}
ll LastTrue(ll l,ll r,function<bool(ll)>f) {
    while(l<r){
    ll mid=l+(r-l+1)/2;
    f(mid)?l=mid:r=mid-1;} 
    return l;
}
 
template<class T> void UniqeVector(vector<T>& v) { 
    sort(all(v)); v.erase(unique(all(v)),end(v)); }
 
// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);
 
template<class T> void re(T& x) { cin >> x; }
void re(double & d) { string t; re(t); d = stod(t); }
void re(ld& d) { string t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
 
template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { each(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { each(a,x) re(a); }
 
// TO_STRING
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
string ts(bool b) { 
    #ifdef LOCAL
        return b ? "true" : "false"; 
    #else 
        return ts((int)b);
    #endif
}
template<class A> string ts(complex<A> c) { 
    stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) {
    string res = "{"; lp(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
    string res = ""; lp(i,SZ) res += char('0'+b[i]);
    return res; }
template<class A, class B> string ts(pair<A,B> p);
template<class T> string ts(T v) { // containers with begin(), end()
    #ifdef LOCAL
        bool fst = 1; str res = "{";
        for (const auto& x: v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(x);
        }
        res += "}"; return res;
    #else
        bool fst = 1; string res = "";
        for (const auto& x: v) {
            if (!fst) res += " ";
            fst = 0; res += ts(x);
        }
        return res;
 
    #endif
}
template<class A, class B> string ts(pair<A,B> p) {
    #ifdef LOCAL
        return "("+ts(p.f)+", "+ts(p.s)+")"; 
    #else
        return ts(p.f)+" "+ts(p.s);
    #endif
}
 
// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
    pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
    pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
void prsz (vector <int> &v){
    pr(sz(v),'\n');
    pr(v);
}

const int di[8] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
const int dj[8] = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};

/***********************************************************/

void Suhaib_Sawalha (){

    int n;
    re(n);
    pr(n>=30?"Yes":"No");

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
// int _;cin>>_;for(int i=1;i<=_;++i,cout<<'\n')
        // cout<<"Case #"<<i<<":\n", 
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}