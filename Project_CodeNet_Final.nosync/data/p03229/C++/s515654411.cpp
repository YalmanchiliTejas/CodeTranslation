#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()



int main() {
    //ll ans = 0;
    int n = 0;
    vi v;
    vl ansv1, ansv2;

    cin>>n;

    v.resize(n);
    
    REP(i,n) cin>>v[i];

    sort(v.begin(), v.end());

    int loop = 0;
    for(loop = 0; loop<round((float)n/2); loop++)
    {
        ansv1.emplace_back(v[n-loop-1]);
        ansv1.emplace_back(v[loop]);
        ansv2.emplace_back(v[loop]);
        ansv2.emplace_back(v[n-loop-1]);
    }

    //DEBUG_VEC(ansv1);
    //DEBUG_VEC(ansv2);

    ll ans1 = 0, ans2 = 0;
    FOR(i,1,n-1)
    {
        ans1 += abs(ansv1[i] - ansv1[i-1]);
    }
    ans1 += abs(ansv1[n-1] - ansv1[0]);

    FOR(i,1,n-1)
    {
        ans2 += abs(ansv2[i] - ansv2[i-1]);
    }
    ans2 += abs(ansv2[n-1] - ansv2[0]);

    cout << max(ans1,ans2) << endl;
}