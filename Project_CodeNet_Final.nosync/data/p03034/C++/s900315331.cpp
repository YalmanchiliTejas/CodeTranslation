#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,A,B,L;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll MOD = (1e+9) + 7;

int main() {
    cin>>N;
    vec s(N);
    rep(i,N) cin>>s[i];
    ll ans = 0;
    reps(i,1,N){//i = A-B
        ll lsum = 0, rsum = 0;
        reps(j,1,N/i){
            ll index = i*j, rindex = (N-1) - i*j;
            if(((N-1)%i == 0) && (index*2 >= N-1)) break;
            lsum += s.at(index);
            rsum += s.at(rindex);
            /*if(ans < lsum + rsum){
                cout<<i<<' '<<j<<' '<<lsum<<' '<<rsum<<endl;
            }*/
            ans = max(ans,lsum+rsum);
        }
    }
    cout<<ans<<endl;
}
