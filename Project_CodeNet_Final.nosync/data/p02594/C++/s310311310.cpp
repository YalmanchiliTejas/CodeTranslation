#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 3e3 + 9;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> LL;

ll n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>n;
    if (n >= 30) cout<< "Yes";
    else cout<<"No";
}

