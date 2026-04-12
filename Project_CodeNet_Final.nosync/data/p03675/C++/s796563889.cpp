#include <bits/stdc++.h>
using  namespace  std;

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define mst(ss,b) memset(ss,b,sizeof(ss));
#define dbg(x) cout << #x << "= " << x << endl;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll INF = (1LL<<62)-1;
const ll mod = 1e9+7;
const int N = 2e5+5;

int a[N];
vector<int>ans;
int n;

int  main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)scanf("%d", &a[i]);
    if(n&1){
        int sz = n;
        while(sz > 0){
            ans.pb(a[sz]);
            sz -= 2;
        }
        sz = 2;
        while(sz < n){
            ans.pb(a[sz]);
            sz += 2;
        }
    }
    else{
        int sz = n;
        while(sz > 0){
            ans.pb(a[sz]);
            sz -= 2;
        }
        sz = 1;
        while(sz < n){
            ans.pb(a[sz]);
            sz += 2;
        }
    }
    for(auto x : ans)printf("%d ", x);
    puts("");
    return 0;
}


//    lower_bound()
//    __builtin_popcount()
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    const double eps=1e-12;
//    #pragma comment(linker,"/STACK:102400000,102400000")

