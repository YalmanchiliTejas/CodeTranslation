#include<bits/stdc++.h>
 
#define X first
#define Y second
#define eb push_back
#define pb pop_back
#define mp make_pair
#define siz(a) int(a.size())
//for traversing the container (bcoz we cannot access linked list etc with direct index)
//c stands for container and it for iterator
#define tr(c, it) \
		for(typeof(c.begin()) it=c.begin() ; it != c.end() ; it++)
		
#define all(c) c.begin(), c.end()
#define present(container, element) (container.find(element) != container.end()) //whether the element is present in the container
 
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define scan(x) scanf("%lld", &x)
#define print(x) printf("%lld", x)
#define pN printf("\n");
//#define mod (((ll)1000000000) * ((ll)1000000000))
using namespace std;
 
typedef  long long     int ll;
typedef unsigned long long int ull;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef pair < int , int > ii;
const ll mod=1e9+7;
const ll mod2=1e9+9;
const ll maxn = 2e5+5;
const ll maxn1 = 1e7+1;
const int root=1e6+5;
const long long inf = 1e18 + 18;
double pie4=3.1415926535;
vector<ll>v ;
ll a[maxn] ;	
	
int main(){
	
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	ll i, n, x, y ;
	
	cin >> n;
	
	for (i = 1; i <= n; i++){

		cin >> a[i] ;
		
		v.eb(a[i]);
	}
	
	sort(v.begin(), v.end());
	
	x = v[n/2-1];
	y = v[n/2] ;
	
	if(x==y){
		
		for(i = 1; i <= n; i++)
		cout << x <<endl ;
	}
	
	else{
		
		for(i = 1; i <=n; i++){
			
			if(a[i] <= x)
			cout << y <<endl ;
			
			else if(a[i] >= y)
			cout << x <<endl;
		}
	}
}
			
			 
	
