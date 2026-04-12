#include <bits/stdc++.h>
typedef long long ll;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define x first
#define y second
#define loop(i, start, end) for(int i=start; i<=end; ++i)
#define loopr(i, end, start) for(int i=end; i>=start; --i)
#define pb push_back
#define MOD 1000000007
using namespace std;
    
template <typename T>
void cloneArray(T *a, T *b, int start, int end) {
    loop(i, start, end) {
        *(b+i)=*(a+i);
    }
}
    
template <typename T>
void inputArray(T *a, int start, int end) {
    loop(i, start, end) cin >> a[i];
}
    
template <typename T>
void printArray(T *a, int start, int end) {
    loop(i, start, end) cout << *(a+i) << ' ';
}
    
void ruffleSort(int *a, int n) {
    unsigned seed=0;
    shuffle(a, a+n, default_random_engine(seed));
    sort(a, a+n);
}

ll mod_add(ll a, ll b) {
    return ((a%MOD)+(b%MOD))%MOD;
}

ll mod_mult(ll a, ll b) {
    return ((a%MOD)*(b%MOD))%MOD;
}
   
int main(int argc, char const *argv[])
{   
    IOS;
    int n;
    cin >> n;
    int a[n+5];
    ll pre[n+5]={}, sum=0;
    inputArray(a, 1, n);
    loop(i, 1, n) pre[i]=pre[i-1]+a[i];
    loop(i, 1, n) {
        sum=mod_add(sum, mod_mult(a[i], pre[n]-pre[i]));
    }
    cout << sum;
    //cerr<<" Execution : "<<(1.0*clock())/CLOCKS_PER_SEC<<"s \n";
    return 0;
}