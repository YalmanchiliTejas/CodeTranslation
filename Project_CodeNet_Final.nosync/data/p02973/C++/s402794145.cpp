#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;


typedef pair<ll,ll> pll;


ll n;
ll a[100005];
set<pll> S;
int main()
{
        cin >> n;
        for(ll i=1;i<=n;i++) {
                cin >> a[i];
                if(S.empty()) S.insert(make_pair(a[i], i));
                else {

                        auto it = S.lower_bound(make_pair(a[i], -1));
                        if(it == S.begin()) S.insert(make_pair(a[i], i));
                        else {
                                        it--;
                                pll X = *it;
                                S.erase(it);
                                S.insert(make_pair(a[i], i));
                        }
                }
        }
        cout << S.size() << endl;
        return 0;
}
