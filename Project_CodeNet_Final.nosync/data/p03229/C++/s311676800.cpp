    #include<bits/stdc++.h>


    #define s scanf
    #define p printf
    #define pb push_back
    #define all(x) x.begin(), x.end()
    #define tmax(a, b, c) max(max(a, b), c)

    using namespace std;

    const int INF = 1e9;
    const long long LINF = 1e18+5;
    const double eps = 0.0000001;
    fstream fin, fout;
    typedef pair<int, int> ii;
    typedef vector<ii> vii;
    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<bool> vb;
    typedef vector<char> vc;
    typedef vector<vector<int> > vvi;
    typedef vector<ll> vll;

    int main(){
    int n; cin >> n;
    vll q(n); for(ll &i : q) cin >> i;
    sort(all(q));
    vll d, t;
    ll suma = 0, sumb = 0;
    int i = 0, j = n - 1;
    while(i < j){
        d.pb(q[i]); d.pb(q[j]);
        t.pb(q[j--]); t.pb(q[i++]);
    }
    if(n % 2){
        d.pb(q[i]); t.pb(q[i]);
    }
    for(int i = 1; i < n; i++)
    {
        suma+= abs(d[i] - d[i-1]);
        sumb+= abs(t[i] - t[i-1]);
    }
        suma = max(suma - abs(d[n-1] - d[n-2]) + abs(d[n-1] - d[0]), suma);
        sumb = max(sumb - abs(t[n-1] - t[n-2]) + abs(t[n-1] - t[0]), sumb);
    cout << max(suma, sumb);
    }
