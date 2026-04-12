
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
//Required Headers
using namespace std;

#define PI 3.1415926535897932384626
#define sp(x,y)                     fixed<<setprecision(y)<<x
#define mk(arr,n,type)              type *arr=new type[n]; // dynamic allocation of memory
#define del(arr)                    delete []arr;           // deletion of allocated memory
const int mod = 1'000'000'007;


//for loops

#define fo(i, n) for(i=0; i<n; i++)	
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define fo2(i, n,t) for(i=0; i<n; i+=t)	

//essentials

#define tc(t)               ll t;ll i; cin>>t; fo(i,t)
#define ll long long

//STL

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vbe(x) x.begin(), x.end()
#define sortvbe(x) sort(vbe(x))
#define setit(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef map<int,int>    mii;
typedef map<ll,ll>      mll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
typedef set<int>        si;
typedef set<ll>         sl;


//inputs

#define ci(x)	    cin>>x;
#define ci2(x,y)    cin>>x>>y;

//template<typename... T>
//void read(T&... args) {
//	((cin >> args), ...);
//}

//outputs

#define pi(x)	    cout<<x;
#define pinl(x)     cout<<x<<endl;

//template<typename... T>
//void write(T&&... args) { //rvalue reference is new to C++ 
//	((cout << args << " "), ...);
//}

//some imp func

inline int gcd(int a,int b) {if (a==0) return b; else return gcd(b%a,a);}
inline void take_input(int A[],int n){for(int i=0;i<n;i++){ cin>>A[i];}}
inline void show(int *A,int n){for(int i=0;i<n;i++){cout<<A[i]<<" ";}cout<<endl;}
inline bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); } 
inline bool sortbysecdesc(const pair<int,int> &a, const pair<int,int> &b) { return (a.second > b.second); } 
inline void swap(int &a,int &b){int temp=a;a=b;b=temp;}
inline void initialise(int A[],int n,int k){for(int i=0;i<n;i++){A[i]=k;}}
inline void vect_input(vector<int>&v,int n){for(int i=0;i<n;i++){int input;cin>>input;v.pb(input);}}
inline int modulo(int a,int b){return (b+(a%b))%b;} 
inline int getascii(char ch){return (int)ch;}
template<typename T>
void show_vect(vector<T> v){for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl;}
template<typename T>
void vect_input(vector<T>&v,T n){for(int i=0;i<n;i++){cin>>v[i];}}
int fact(int n) { return (n==1 || n==0) ? 1: n * fact(n - 1);  } 



//debugging

#define deb(x) cout << #x << " = " << x << endl; //to check the values
#define deb2(x, y) cout << #x << " = " << x << "," << #y << " = " << y << endl;

void A_A()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    freopen("error.in","w",stderr);
    #endif
}
ll num;
void solve(){
	ll i,j,n,sum=0,m=0;
	ll mod=1000000007;
	cin>>n;
	vl a(n);
    // set <ll> s;
	fo(i,n){
	    cin>>num;
	    a.pb(num);
	   // s.insert(num);
    }
	for(ll i:a){
	    sum=((sum%mod)+((m%mod)*(i%mod))%mod)%mod;
	   // deb(sum)
	    m=((m%mod)+(i%mod))%mod;
	   // deb(m)
	   // m=((s[i]%mod)*(s[i+1]%mod))%mod
	}
	cout<<sum%mod;
	
}
int main(){
// 	A_A();
// 	tc(t){
		solve();
// 	}
	return 0;
}
