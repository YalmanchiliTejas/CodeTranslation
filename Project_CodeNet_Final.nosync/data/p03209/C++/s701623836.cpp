#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define nl '\n'
#define INF 2147483647
#define si(i) scanf("%d", &i)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, x;

ll eat( ll sz, ll btm ){
    if( sz == 0 ){
        if( btm > 0 ) return 1;
        else return 0;
    }
    if( btm <= ((ll)1 << (sz + 1)) - 2 ) return eat( sz - 1, btm - 1);
    else return ((ll)1<<sz) + eat( sz - 1, btm - ( (ll)1 << (sz + 1)) + 1  );
}

int main(){
    cin >> n >> x;
    cout << eat( n, x ) << nl;
}