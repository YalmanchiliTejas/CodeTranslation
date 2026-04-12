
#include <bits/stdc++.h>

using namespace std;

#define rep(i, x)   for (__typeof(x) i = 0; i < x; i++)
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define repi(i, x)  for (__typeof(x) i = x-1; i >= 0; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
typedef vector<vector<int> > vvi;
const   int            infi = numeric_limits<int>::max();
const   double         eps = 0;
const   int            ms  = 0;

vector<ll> B(51, 0), P(51, 0), H(51, 0);
ll n , x;


int main()
{
    ios::sync_with_stdio(false);//endl->"\n"
    cin.tie(0);
    cin >> n >> x;

    B[0] = 0;
    P[0] = 1;
    H[0] = 1;
    for(int i = 1; i <= 50; i++){
        B[i] = B[i-1]*2+2;
        P[i] = P[i-1]*2+1;
        H[i] = B[i] + P[i];
    }
    
    int l = n;
    ll ans = 0;
    while(1){
        
        debug(x);
        if(x == H[l]){
            ans += P[l];
            break;
        }
        if(x <= 1)break;
        if(l==0)break;
        if(1+H[l-1]+1 < x){
            
            x-=H[l-1]+1+1;
            ans+=1+P[l-1];
            l--;
        } else if(1+H[l-1]+1 == x){
            ans+=1+P[l-1];
            break;
        } else if(1+H[l-1]==x){
            ans+=P[l-1];
            break;
        }
        else{
            l--;
            x-=1;
        }
    }
    cout << ans << "\n";
    return 0;
}