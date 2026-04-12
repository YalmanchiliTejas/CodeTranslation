#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";}

// #define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
typedef long long ll;
typedef double ld;
#define pll pair<ll,ll>
#define pii pair<int, int>
#define pb push_back
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define I insert
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
   
const ll Mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int n , x; cin >> n;
    deque<int> Q;
    cin >> x;
    Q.pb(x);
    int length = 1;
    for(int i = 0 ;i < n-1 ; i++){
        cin >> x;
        if(x <= Q[0]){
            Q.push_front(x);
            length++;
        }
        else if(x > Q[length-1])
            Q[length-1] = x;
        else{
            int l = 0 , r = length-1 , ans = -1;
            while(l <= r){
                int mid = (l+r)/2;
                if(Q[mid] <  x){
                    ans = mid;
                     l = mid+1;
                }
                else    
                    r = mid-1;
            }
            Q[ans] = x;
        }        
    }
    cout << length << endl;
    return 0;
}