
#include<bits/stdc++.h>


using namespace std;

using ll   = long long;
using ii   = pair   < int , int >;
using i3   = pair   < int , ii  >;
using li   = pair   < ll  , int >;
using lii  = pair   < ll  , ii  >;
using pll  = pair   < ll  , ll  >;
using vi   = vector < int       >;
using vl   = vector < ll        >;
using vii  = vector < ii        >;
using vli  = vector < li        >;
using vpll = vector < pll       >;
using vi3  = vector < i3        >;
using vlii = vector < lii       >;


const int N = 2e5 + 5;
const ll INF = 1e17 + 7;
const double eps = 1e-9 , PI = acos(-1);


int n , k;

ll mem[N][5][3];
int a[N];

ll dp(int i , int cnt , int f){
    if(cnt > k)return 0;
    if(i == n){
            if(cnt == k)return 1ll;
            return 0;
    }
    ll &ret = mem[i][cnt][f];
    if(ret != -1)return ret;

    int mn = 0;
    int mx = a[i];
    if(f)mx = 9;

    ret = 0;
    for(int j = mn ; j <= mx ; j ++){
            ret += dp(i + 1 , cnt + (j != 0) , f | j < mx);
    }

    return ret;
}

void solve(int testCase){

    string s; cin >> s;
    for(int i = 0 ; s[i] ; i ++){
            a[i] = int(s[i] - '0');
    }
    n = s.length();

    scanf("%d" , &k);

    memset(mem , -1 , sizeof mem);
    ll ans = dp(0 , 0 , 0);

    printf("%lld\n" , ans);

}

main(){

    int t = 1;
    // scanf("%d" , &t);

    for(int testCase = 1 ; testCase <= t ; testCase ++){
            solve(testCase);
    }

    return 0;
}
