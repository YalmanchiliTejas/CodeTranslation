#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define si(X) scanf("%d", &(X))
#define sll(X) scanf("%lld",&(X))
#define INFL 0x3f3f3f3f3f3f3f3fLL
typedef vector<vector<ll> > matrix;
const int mod = 1e9+7;
ll gcd(ll a,ll b){
	if(b==0)return a;return gcd(b,a%b);
}
ll expo(ll base,ll pow){
    ll ans = 1;
    while(pow!=0){
        if(pow&1==1){ans = ans*base;ans = ans%mod;}
        base *= base;base%=mod;pow/=2;}return ans;
}
ll inv(ll x){return expo(x,mod-2);}

double pi = 3.141592653589793238462643;
double error = 0.0000001;
int dx[8] = {1 , 0 , -1 , 0 , 1 , -1 , -1 , 1};    // last 4 diagonal
int dy[8] = {0 , 1 , 0 , -1 , 1 , 1 , -1 , -1};
/* -------Template ends here-------- */

const int M = 100001;

vector<ll> vec;

int main(){
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);



    int n;
    si(n);
    ll el;

    for(int i = 1 ; i <= n ; i++){
        sll(el);
        vec.push_back(el);
    }

    ll ans = 0;

    ll large = 1e16;

    int steps = 0;

    while(1){
        sort(vec.begin() , vec.end());
        ll term = vec[n - 1];
        /*for(int i = 0 ; i < vec.size() ; i++){
            cout<<vec[i]<<"  ";
        }
        cout<<endl<<endl;*/
        if(term < n) break;
        ll lo = 0 , hi = large;
        ll here = 0;

        while(lo <= hi){
            ll mid = (lo + hi)/2;
            ll mak = term - mid*(n);
            if(mak >= n){
                lo = mid + 1;
            }
            else{
                here = mid;
                hi = mid - 1;
            }
        }
       // if(steps > 20) break;
        vec[n - 1] -= (here*n);

        for(int i = 0 ; i < n - 1 ; i++){
            vec[i] += (here);
        }

        ans += here;
    }

    cout<<ans;












}












