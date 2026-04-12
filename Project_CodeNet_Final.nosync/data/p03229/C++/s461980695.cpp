#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    vector<ll> A;
    rep(i,N) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    deque<ll> B;
    rep(i,N) {
        B.push_back(A[i]);
    }
    ll ans = 0;
    int nmax,nmin;
    nmax = B.back();
    nmin = B.front();
    ans += nmax - nmin;
    B.pop_back();
    B.pop_front();
    while(B.size()>0) {
        ll t1,t2;
        t1 = B.back();
        t2 = B.front();
        ll tmp11,tmp12,tmp21,tmp22;
        tmp11 = abs(t1-nmax);
        tmp12 = abs(t1-nmin);
        tmp21 = abs(t2-nmax);
        tmp22 = abs(t2-nmin);

        if (tmp11>=tmp12 && tmp11>=tmp21 && tmp11>=tmp22) {
            ans+=tmp11;
            nmax=t1;
            B.pop_back();
        }
        else if (tmp21>=tmp11 && tmp21>=tmp11 && tmp21>=tmp22) {
            ans+=tmp21;
            nmax=t2;
            B.pop_front();
        }
        else if (tmp12>=tmp11 && tmp12>=tmp21 && tmp12>=tmp22) {
            ans+=tmp12;
            nmin=t1;
            B.pop_back();
        }
        else {
            ans+=tmp22;
            nmin=t2;
            B.pop_front();
        }
    }
    cout << ans << endl;
}
