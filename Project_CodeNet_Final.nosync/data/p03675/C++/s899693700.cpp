#include <bits/stdc++.h>

/*..DEFINITIONS .... */
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);
#define T() int tt; cin>>tt; while(tt--)
#define mp make_pair
#define pb push_back
#define lchild (2*node+1)
#define rchild (2*node+2)
#define f first
#define s second
#define br cout<<endl
#define MOD (1000000007LL)
using namespace std;

/*...TYPEDEFS....*/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*...USEFUL FUNCTIONS....*/
ll gcd(ll a, ll b){
    if(b==0)return a;
    else gcd(b, a%b);
}
ll pwr(ll base, ll exp, ll mod=MOD){
    ll tmp = 1;
    while(exp > 0)
	{
        if(exp%2)
		{
			tmp=(tmp*base)%mod;
	    }
		base=(base*base)%mod;
		exp/=2;
    }
    return tmp;
}


int main(){
FIO
int n;
cin >> n;
int a[n];

for(int i=0; i<n; ++i){
    cin >> a[i];
}
deque<int> dq;
if(n&1){
    for(int i=0; i<n; ++i){
        if(!(i&1)){
            dq.push_front(a[i]);
        }
        else{
            dq.pb(a[i]);
        }
    }
}
else{
    for(int i=0; i<n; ++i){
        if(!(i&1)){
            dq.pb(a[i]);
        }
        else{
            dq.push_front(a[i]);
        }
    }
}
for(int i=0; i<dq.size(); ++i){
    cout << dq[i] << " ";
}
cout << "\n";







return 0;
}
