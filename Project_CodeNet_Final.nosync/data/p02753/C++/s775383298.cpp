#include<bits/stdc++.h>

using namespace std;
#define ll  long long
#define ld  long double

#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int MAXN = 1e5 + 5;
string h;
int a, b, k;

ll fastPow(ll x, ll b) {
    if (b == 0)
        return 1;
    else if (!(b & 1)) {
        return fastPow(x * x, b / 2);
    } else
        return x * fastPow(x * x, (b - 1) / 2);
}

//__builtin_popcount ();
ll arr[MAXN],ok1[MAXN],pre[MAXN],pre1[MAXN];

int main() {
    FAST
   string h;
    cin>>h;
    set<char>s;
    s.insert(h[0]);
    s.insert(h[1]);
    s.insert(h[2]);
    if(s.size()==1)
    {
        cout<<"No"<<endl;
    }
    else
        cout<<"Yes"<<endl;
    return 0;
}