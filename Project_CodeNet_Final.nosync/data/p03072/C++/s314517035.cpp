    /**

       Author : sea_26

    **/


    #pragma GCC optimize("03")
    #include <bits/stdc++.h>

    using namespace std;

    const int M = 1000000007;
    const double PI = acos(-1.0);

    // const double pi = atan2(0, -1);
    // const double PI = 4 * atan(1);
    // const double pi = 2*cos(0.0);

    typedef long long ll;
    typedef long double ld;

    const int iinf = 0x3f3f3f3f;
    const ll linf = 0x3f3f3f3f3f3f3f3f;

    #define mp make_pair
    #define pb push_back
    #define f first
    #define s second
    #define ln(x) (int)x.size()

    #define bp(n)  __builtin_popcount(n)
    #define bclz(n) __builtin_clzll(n)
    #define bctz(n) __builtin_ctzll(n)
    #define bip(n) __builtin_parity(n)

    #define vsort(v) sort(v.begin(),v.end())
    #define rvsort(v) sort(v.begin(),v.end(),greater<int>())

    #define rep(n) for(int i=0; i<n; i++)
    #define rrep(n) for(int i=n-1; i>=0; i--)
    #define lrep(p,q) for(int i=p; i<=q; i++)
    #define prep(n) for(int i=1; i*i<=n; i++)
    #define it(a, x)  for(auto &a : x)
    #define yes cout << "YES" << endl
    #define no cout << "NO" << endl

    priority_queue<int> pq;

    #define fs   ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    template< typename T> inline T lcm(T a, T b){ return (a / gcd(a,b)) * b; }
    template< typename T> inline T MAX(T a, T b){ return a ^ ((a ^ b) & -(a < b)); }
    template< typename T> inline T MIN(T a, T b){ return b ^ ((a ^ b) & -(a < b)); }
    template< typename T> void tpns(T n){ rrep(30){ if(n & (1 << i)) pq.push(1 << i); } }
    template< typename T> void SWAP(T &a, T &b){ a = ((a) ^= (b)),  b = ((b) ^= (a)),  a = ((a) ^= (b)); }
    template< typename T> inline T ABS(T a){ int x = a >> sizeof(int) * CHAR_BIT - 1; return (a + x) ^ x; }
    template< typename T> inline T mod(T a, T b){ return a >= b ? a % b : a; }
    template< typename T> inline T gcd(T a, T b){ while (b) b ^= a ^= b ^= a %= b; return a; }

    ll gcdextd(ll a, ll b, ll& x, ll& y) {
        if (!a) { x = 0; y = 1; return b; }
        ll y1,d;
        d = gcdextd(b % a, a, y, y1);
        x = y1 - (b / a) * y;
        return d;
    }



    double WT() {
    	return double(clock()) / CLOCKS_PER_SEC;
    }

    void ReT(){

    	cout << "\nTime = " << fixed << setprecision(3) << WT()  << " Sec"<< endl;

    exit(0);
    }


    int n,cnt;
    int main(){

            fs;
            cin >> n;
            vector<int> v(n);

            rep(n)
                cin >> v[i];
            rep(n){
                bool flag = true;
                for(int j=0; j<i; j++){
                    if(v[j] > v[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
        cout << cnt << endl;
         //   ReT();

    }
