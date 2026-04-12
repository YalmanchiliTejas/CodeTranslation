#include <bits/stdc++.h>

using namespace std;

template<class e, class t, int N>
std::basic_istream<e,t>& operator>>(std::basic_istream<e,t>& in, const e(&literal)[N]) {
        std::array<e, N-1> buffer; //get buffer
        in >> buffer[0]; //skips whitespace
        if (N>2)
                in.read(&buffer[1], N-2); //read the rest
        if (strncmp(&buffer[0], literal, N-1)) //if it failed
                in.setstate(in.rdstate() | std::ios::badbit); //set the state
        return in;
}
template<class e, class t>
std::basic_istream<e,t>& operator>>(std::basic_istream<e,t>& in, const e& literal) {
        e buffer;  //get buffer
        in >> buffer; //read data
        if (buffer != literal) //if it failed
                in.setstate(in.rdstate() | std::ios::badbit); //set the state
        return in;
}
//redirect mutable char arrays to their normal function
template<class e, class t, int N>
std::basic_istream<e,t>& operator>>(std::basic_istream<e,t>& in, e(&carray)[N]) {
        return std::operator>>(in, carray);
}

template<class t> 
ostream & operator<<(ostream & out, vector<t> & a){
    for(auto x : a){
        out << x <<" ";
    }
    return out;
}


template<class t1,class t2>
ostream & operator<<(ostream & out,const pair<t1,t2> & a){
    out << a.first<<" "<<a.second;
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


//#define PRAGMA 448
#ifdef PRAGMA
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
 
#ifdef LUCARIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#define CK clock_t start = clock();
#define PCK cout<<setprecision(7)<<endl<<"Tiempo transcurrido: "<<((double)clock() - start) / CLOCKS_PER_SEC<<endl;
#else
#define deb(...) 0
#define deb1(x) 0
#define CK 0
#define PCK 0
#endif
 
typedef pair<long long,long long> pll;
typedef pair<int,int> pii;
typedef pair<string,int> psi;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define bs binary_search 
#define up upper_bound // >
#define lb lower_bound // >=
#define f first 
#define s second 
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define mp make_pair     
#define endl "\n" 
 
#define fore(i,a,b) for(ll i = a; i < (int)b; i++)
#define rfore(i, a, b) for(ll i = b - 1; i >= (int)a; i--)
#define mm(a,b) memset(a , b , sizeof a) 
#define trans(a,b) transform(a.begin(),a.end(),a.begin(),b) //::tolower ::toupper
#define np(a) next_permutation(a.begin(), a.end())
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define sfind(s,t) (s.find(t) != string::npos)
 
#define infll (ll)(1e15+3)
#define infi  (ll)(1e9+4)
//#define pi 3.14159265359 
#define mod (ll)(1e9+7)
#define eps  1e-7
#define YES "YES"
#define NO "NO"

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll fpow(ll b, ll e, ll m = mod){if(!e)return 1;ll q=fpow(b,e/2,m);q=(q*q)%m;return e&1?(b*q)%m:q;}


#define oper max
#define NEUT 0
#define LNEUT 0
struct STree { // example: range sum with range addition
    vector<int> st,lazy;int n;
    STree(int n): st(4*n+5,NEUT), lazy(4*n+5,LNEUT), n(n) {}

    void push(int k, int s, int e){
        if(!lazy[k])return; // if neutral, nothing to do
        st[k]+=lazy[k]; // update st according to lazy
        if(s+1<e){ // propagate to children
            lazy[2*k]+=lazy[k];
            lazy[2*k+1]+=lazy[k];
        }
        lazy[k]=LNEUT; // clear node lazy
    }
    void upd(int k, int s, int e, int a, int b, int v){
        push(k,s,e);
        if(s>=b||e<=a)return;
        if(s>=a&&e<=b){
            lazy[k]+=v; // accumulate lazy
            push(k,s,e);return;
        }
        int m=(s+e)/2;
        upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
        st[k]=oper(st[2*k],st[2*k+1]); // operation
    }
    int query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return 0; // operation neutral
        push(k,s,e);
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
    }
    void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
    int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);



int32_t main(int32_t argc, char const *argv[]){
CK; FIN;

    int n,m;cin>>n>>m;
    pair<pll,int> a[m];
    vector<pair<pll,int> > b[n+2];
    STree st(n+4);
    fore(i,0,m){
        cin>>a[i].ff>>a[i].fs>>a[i].s;
    }
    fore(i,0,m){
        b[a[i].ff].pb(a[i]);
    }
    int maxi = 0;
    rfore(i,0,n){
        for(auto x : b[i+1]){
            st.upd(x.ff,x.fs+1,x.s);
            
        }
        int m =st.query(i,n+1);

        st.upd(i,i+1,m);
    }
    
    cout<<st.query(0,1)<<endl;



        
PCK;return 0;    
}



/*


Para las DP:

sLos arreglos donde estén los valores en lo posible se declaran como INT
siempre hacer int &r = dp...    
int res y trabapiijas todo con res
    luego haces return r = res
cuando se trabaja se hace solve(...)+a[x];

break;
Fórmulas:

priority_queue < int,vector<int>,greater<int> > q; calse contenedor y comparacion
continue
break
cero = r/k  - (l/k + (l%k!=0)) +1; cantidad de números divisibles por k en el intervalo [l, r]
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
    nombre.resize(tam,contenido si se agregan) //cambia el tamaño a tam
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




