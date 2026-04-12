#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define loop(i,l,r) for(int i = (l); i < (r); i++)
#define rloop(i,r,l) for(int i = (r-1); i >= (l); i--)
#define refloop(x, v) for(auto& x : (v))
#define exists(m,e) if((m).find(e) != (m).end())
#define nexists(m,e) if((m).find(e) == (m).end())
#define sortaka(v) sort((v).begin(), (v).end())
#define rsort(v) sort((v).rbegin(), (v).rend())
#define lower_bound_index(v, x) (lower_bound((v).begin(), (v).end(), x)-(v).begin()) // returns minimum i s.t v[i] >= x
#define upper_bound_index(v, x) (upper_bound((v).begin(), (v).end(), x)-(v).begin()) // returns minimum i s.t v[i] > x
#define scanint(x) scanf("%d", &(x))
#define scanfloat(x) scanf("%f", &(x))
#define scanll(x) scanf("%lld", &(x))
#define scanchar(x) scanf("%c", &(x))
#define scanstring(x) scanf("%s", &(x))
#define printint(x) printf("%d", x)
#define printfloat(x) printf("%.9f", x)
#define printll(x) printf("%lld", x)
#define printchar(x) printf("%c", x)
#define printstring(x) printf("%s", x)
#define printintnewline(x) printf("%d\n", x)
#define printfloatnewline(x) printf("%.9f\n", x)
#define printllnewline(x) printf("%lld\n", x)
#define printcharnewline(x) printf("%c\n", x)
#define printstringnewline(x) printf("%s\n", x)
#define square(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))

typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef vector<string> vs;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<pair<long long, long long>>> vvpll;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll n, x, m; cin >> n >> x >> m;
    ll ans = 0;

    vl rems(m+1);
    map<ll,int>counts;
    rems[0] = x;
    counts[x] = 1;

    for(int i = 1; i < m+1; i++){
        rems[i] = (rems[i-1]*rems[i-1])%m;
        exists(counts, rems[i]){
            counts[rems[i]]++;
        }else{
            counts[rems[i]] = 1;
        }
    }

    if(n <= m){
        for(int i = 0; i < n; i++){
            ans += rems[i];
        }
        cout<<ans<<endl;
        return 0;
    }

    ll ind = 0;
    while(counts[rems[ind]] == 1){
        ind++;
    }

    ll ind2 = ind+1;
    while(rems[ind] != rems[ind2]){
        ind2++;
    }

    ll periodlen = ind2 - ind;


    loop(i, 0, ind){
        ans += rems[i];
    }

    loop(i, 0, (n-ind)%periodlen){
        ans += rems[ind+i];
    }

    ll perans = 0;
    loop(i, ind, ind2){
        perans += rems[i];
    }
    ans += perans*((n-ind)/periodlen);

    cout<<ans<<endl;
}