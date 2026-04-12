#include <bits/stdc++.h>
#include <unistd.h>
#include <omp.h>
 
using namespace std;
 
template<class t>
istream & operator>>(istream& in,vector<t> &v) {
    for(int i = 0; i < (int)v.size();i++)in >> v[i];
    return in;
}
template<class t1,class t2>
istream & operator>>(istream& in,pair<t1,t2> &v) {
    in >> v.first >> v.second;
    return in;
}
template<class t1,class t2>
ostream & operator<<(ostream & out,const pair<t1,t2> & a){
    out << a.first<<" "<<a.second;
    return out;
}
template<class t> 
ostream & operator<<(ostream & out, vector<t> & a){
    for(auto x : a)
        out << x <<" ";
    return out;
}
 
template<class t> 
ostream & operator<<(ostream & out, set<t> & a){
    for(auto x : a)
        out << x <<" ";
    return out;
}
template<class t> 
ostream & operator<<(ostream & out, multiset<t> & a){
    for(auto x : a)
    	out << x <<" ";
    return out;
}
template<class t1, class t2> 
ostream & operator<<(ostream & out, map<t1,t2> & a){
    for(auto x : a)
        out << x.first << " = " << x.second << endl; 
    return out;
}
template<class t1,class t2>
pair<t1,t2> operator+(const pair<t2,t1>& a,const pair<t1,t2> & b){
    return {a.first + b.first, a.second + b.second};
}
template<class t1,class t2>
pair<t1,t2> operator-(const pair<t2,t1>& a,const pair<t1,t2> & b){
    return {a.first - b.first, a.second - b.second};
}
template<class t1,class t2>
pair<t1,t2> operator+=(pair<t2,t1>& a,const pair<t1,t2> & b){
    return {a=a+b};
}
template<class t1,class t2>
pair<t1,t2> operator-=(pair<t2,t1>& a,const pair<t1,t2> & b){
    return {a=a-b};
}
 
 
//#define PRAGMA 448
#ifdef PRAGMA
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
 
#ifdef LUCARIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl;
#define FIN 0
#else
#define deb(...) 0
#define deb1(x) 0
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#endif
 
typedef pair<long long,long long> pll;
typedef pair<int,int> pii;
typedef pair<string,int> psi;
 
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define bs binary_search 
#define up upper_bound // >
#define lb lower_bound // >=
#define f first 
#define s second 
#define fst first 
#define snd second 
#define ff first.first
#define fs first.second
#define sf second.first
//#define ss second.second
#define mp make_pair     
#define endl "\n" 
 
#define fore(i,a,b) for(int i = a; i < (int)b; i++)
#define forej(i,a,b,j) for(int i = a; i< (int)b; i+=j)
#define rfore(i, a, b) for(int i = b - 1; i >= (int)a; i--)
#define bin(aaa,bbb) rfore(_,0,bbb)cout<<((aaa & (1<<_)) != 0);cout<<endl;
#define mm(a,b) memset(a , b , sizeof a) 
#define bi(i,j) ((i&(1<<j))!=0)
#define trans(a,b) transform(a.begin(),a.end(),a.begin(),b) //::tolower ::toupper
#define bpop(n) __builtin_popcount(n)
#define np(a) next_permutation(a.begin(), a.end())
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define con(a,b,c) cout<<(a?b:c)<<endl;
#define sfind(s,t) (s.find(t) != string::npos)
 
#define infll (ll)(1e16+3)
#define infi  (ll)(1e9+4)
#define pneut (pll){infll,-infll}
#define Pi acos(-1) 
#define mod (ll)(1e9+7)
#define eps  1e-7
#define YES "YES"
#define NO "NO"
 
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll fpow(ll b, ll e, ll m = mod){int r=1;while(e){if(e&1)r=(r*b)%m;e/=2;b=(b*b)%m;}return r;}




int32_t main(int32_t argc, char const *argv[]){
    FIN;
    string s;cin>>s;
    sort(ALL(s));
    con(s[0]!=s[2],"Yes","No");

    return 0;    
} 

/*

Para las DP:
 
sLos arreglos donde estÃ©n los valores en lo posible se declaran como INT
siempre hacer int &r = dp...    
int res y trabapiijas todo con res
lueg    o haces return r = res
cuando se trabaja se hace solve(...)+a[x];
 
break;
FÃ³rmulas:
 
priority_queue < int,vector<int>,greater<int> > q; calse contenedor y comparacion
continue
break
cero = r/k  - (l/k + (l%k!=0)) +1; cantidad de nÃºmeros divisibles por k en el intervalo [l, r]
en un arreglo sircularde largo n si das saltos de largo m para volver al inicion nesesitas
n/gcd(n,m)
cantidad de inmeros en un rango lower_bound(r) -lowerbound(l-1)
upper_bound primer elemento mayor estricto
lower_bound primer elemento mayor o igual
Al hacer BFS con distancia recordar simpre antes de visitar preguntar si ya llegue antes con
un peso menor 
setprecision(15)
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
getline(cin,s); donde s es un string
si luego se van a haces unuevos cins hacer cin.ignore
 
__builtin_popcount(3) cantidad de unos en la reprewsentacion binaria
__builtin_clz() cantidad de 0 a la izquierda del primer numero
 __builtin_ffs evuelve 1+ el indise del uno menos significativo
 
TCL
 
tuple 
    tuple<tipo> nombre
    get<pos>(nombre) //forma de acceder
 
vector
    vector<tipo> nombre(cantidad,contenido)
    vector<int> nombre = {...}
    nombre.resize(tam,contenido si se agregan) //cambia el tamaÃ±o a tam
    nombre.pop_back() elimina el ultimo elemento
    nombre.back() // ultimo elemnto
 
set
    erase(it/elem)
    insert(elem)
 
rectas en un set
 
recta = az+by+c = 0 
recta entre 2 puntos
a = y1-y0 y b = x0-x1 => c = x1*y0-y1*x0
 
if(a<0 || (a==0 && b<0)) {
    a=-a;
    b=-b;
    c=-c;
}
d = gcd(a,b)
a,b /= gcd(a,b);
c,d /= gcd(d,c)
 
luego
 
 
*/