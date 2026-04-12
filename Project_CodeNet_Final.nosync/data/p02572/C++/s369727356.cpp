                                      ///.... In the name of ALLAH .....///

  #include<bits/stdc++.h>

   using namespace std;

/// type define part

  typedef long long ll ;
  typedef double dl;

/// define Part

    #define fast()          ios_base::sync_with_stdio(false);cin.tie(NULL);
    #define PB              push_back
    #define F               first
    #define S               second
    #define MP              make_pair
    #define all(a)          (a).begin(),(a).end()
    #define rall(a)         (a).rbegin(),(a).rend()
    #define sz(x)           (int)x.size()
    #define endl             '\n'
    #define mem(a,b)         memset(a, b, sizeof(a) )
    #define MOD              1000000007
    #define fraction(a)      cout<<fixed; cout<<setprecision(a);
/// value
   const double PI = acos(-1);
   const double eps = 1e-9;
   const int inf = 2000000000;
   const ll infLL = 9000000000000000000;

// debugger

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

void faltu () {
            cerr << endl;
}

template <typename T>
void faltu( T a[], int n ) {
            for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
                cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
            cerr << arg << ' ';
                faltu(rest...);
}

const int mx = 2e5+12;

ll arr[mx];

 int main(){

  fast();

  int n ;
  cin >> n;

  vector < ll > brr;

 for(int i = 1 ; i <=n ; i++) cin >> arr[i];

 brr.push_back(arr[n]);

 int j = 0;

 for(int i = n-1 ; i > 1 ; i--){
    brr.push_back((brr[j]%MOD+arr[i]%MOD)%MOD);
    j++;
 }


 ///dbg(brr);

 int x = sz(brr);

 ll sum = 0;
 for(int i = 1 ; i <n;i++){
    sum = (sum+arr[i]*brr[x-1])%MOD;
    x--;
 }
 cout<<sum<<endl;

  return 0;
 }
