#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

int main() {
    int res = 0;
    int num;

    cin>>num;

    vector<int> h;

    h.resize(num);

    REP(i,num) cin>>h[i];

    int maxh = -1;
    
    REP(i,num)
    {
        if (i==0)
        {
            res++;
            maxh = h[i];
            continue;
        }

        if (maxh <= h[i]) 
        {
            maxh = h[i];
            res++;
        }
    }
    cout << res << endl;
    return 0;
}