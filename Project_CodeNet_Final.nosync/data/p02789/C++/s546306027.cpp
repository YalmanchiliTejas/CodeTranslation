#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG

using _loop_ll = long long;
#define REP(i,n) for(_loop_ll (i)=0; (i)<(_loop_ll)(n); (i)++)
#define FOR(i,a,b) for(_loop_ll (i)=(_loop_ll)(a); (i)<(_loop_ll)(b); (i)++)
#define FORR(i,a,b) for(_loop_ll (i)=(_loop_ll)(b)-1; (i)>=(_loop_ll)(a); (i)--)
 
#define ALL(v) (v).begin(),(v).end()
 
#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl
#define DEBUG_VEC(v) cerr<<#v<<": ";REP(__i,(v).size())cerr<<((v)[__i])<<", ";cerr<<endl

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

constexpr long long int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    if(n == m){ 
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    

    

    return 0;
};
