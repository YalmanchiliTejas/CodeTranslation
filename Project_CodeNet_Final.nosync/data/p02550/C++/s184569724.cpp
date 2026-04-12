#include<bits/stdc++.h>
typedef  long long int ll;
typedef  long double ld;
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define mod 1000000007
#define F first
#define S second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
//recursions\
#pragma comment(linker, "/stack:200000000")
//loops\
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.push_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}
#define EVARS(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}
inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<string>::iterator it) { cerr << endl; }
template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cerr << "; ";
    __evars(++it, args...);
}
const int N = 1e6 + 5;

int main()
{
	sync;
	clock_t clk=clock();
    ll n, x, m;
    cin >> n  >> x >> m;
    x %= m;
    vector<ll> series;
    vector<bool> visited(m + 1, false);
    series.push_back(x);
    visited[x] = 1;
    for(ll i = 2; i <= n; i++)
    {
        x = x * x % m;
        if(visited[x])
            break;
        visited[x] = true;
        series.push_back(x);
    }  
    ll ans = 0;
    if(series.size() == n)
    {  
        //EVARS(series);
        for(ll i = 0; i < n; i++)
            ans = ans + series[i];
    }
    else
    {
        ll find_first = -1;
        for(ll i = 0; i < series.size(); i++)
        {
            if(x == series[i])
            {
                find_first = i;
                break;
            }
            ans = ans + series[i];
        }
        vector<ll> cyc;
        for(ll i = find_first; i < series.size(); i++)
        {
            cyc.push_back(series[i]);
            if(i != find_first)
                cyc[i - find_first] += cyc[i - find_first - 1];
        }
        n -= find_first;
        ll times = n / cyc.size(), remain = n % cyc.size();
        ans = ans + times * cyc.back();
        if(remain)
            ans += cyc[remain - 1];
    }
    cout << ans;
 	//cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';	
}
