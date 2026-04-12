#include <bits/stdc++.h>
using namespace std;
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X)
#define debug(x0123456789) cerr<<#x0123456789<<':'<<x0123456789<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto x0123456789:v)cerr<<x0123456789<<' ';cerr<<endl;
#define INF 1000000007
#define LINF 1000000000000000007
#define EPS 1e-9
typedef long long ll;
typedef long double ld;

signed main(){
    ll X;
    cin >> X;
    if(X==7 || X==5 || X==3){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}