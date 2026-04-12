#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
vector<ll> nolonb(51,0); //the number of layers of LEVEL n burger

ll f(ll n, ll x){
    if(n==0 && x==1) return 1;

    if(x<=0){
        cout << "BUG" << endl;
        return -1;
    }

    if(x==1) return 0;
    else if(x<=1+nolonb.at(n-1)) return f(n-1,x-1);
    else if(x==2+nolonb.at(n-1)) return f(n-1,x-2)+1;
    else if(x<=nolonb.at(n)-1) return f(n-1,nolonb.at(n-1))+1+f(n-1,x-2-nolonb.at(n-1));
    else if(x==nolonb.at(n)) return 1+2*f(n-1,nolonb.at(n-1));

    cout << "BUG" << endl;
    return -1;
}


int main(){
    ll n,x; cin >> n >> x;
    nolonb.at(0) = 1;
    for(int i=1;i<=50;i++) nolonb.at(i) = 3 + 2*nolonb.at(i-1);
  
    //rep(i,51) cout << nolonb.at(i) << " " ; 
    cout << f(n,x) << endl;
}