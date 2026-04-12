// Gaurav Aggarwal

/*
useful stl
array<ll,size> ar;         //size(),front(),back(),fill(),empty()
deque<ll> d                //push_back(),push_front(),pop_front(),pop_back()
vector<ll> v(size,val);    //push_back(),*max_element(v.begin(),v.end()),accumulate(v.begin(),v.end(),0)
stack<ll> g;               //push(),pop(),top(),size(),empty()         LIFO
queue<ll> q;               //push(),size(),front(),back(),empty()      FIFO
priority_queue<ll> pq
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ipair;
typedef pair<long,long> lpair;
typedef pair<double,double> pdd;
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define For(i, a, b) for(__typeof (a) i=a; i<=b; i++)
#define mod 1000000007
#define PI 3.141592653589793238462643383279502884 
#define debug1(a) cout<<a<<"\n";
#define debug2(a,b) cout<<a<<" "<<b<<"\n";
#define debug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define debug_arr(a,n) {for(__typeof (n) i=0; i<n; ++i) {cout<<a[i]<<" ";}}
#define inp_arr(a,n) for(__typeof (n) i=0; i<n; ++i) {cin>>a[i];}
#define beg_arr(a,n) for(__typeof (n) i=0; i<n; ++i) {a[i] = 0;}

ll power(ll x, ll y) 
{ 
    ll res = 1;   
    while (y > 0) { 
        if (y & 1) 
            res = (res*x)%mod; 
        y = y>>1;
        x = (x*x)%mod; 
    } 
    return res%mod; 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout); 
    // #endif  

    int n;
    cin>>n;

    int a[n];
    inp_arr(a,n);

    int maxi = a[0];

    int ans = 1;
    for(int i=1;i<n;++i) {
        if(a[i] >= maxi) {
            ++ans;
            maxi = a[i];
        }
    }   

    cout<<ans;


    return 0;
}