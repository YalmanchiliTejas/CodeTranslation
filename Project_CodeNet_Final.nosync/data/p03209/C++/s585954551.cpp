#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll N,X;
    cin >>N>>X;
    ll mx=1;
    string BG;
    //BG = "P"; 
    if(X<=N){
        cout<<0<<endl;
        return 0;
    }
    vector<ll>P(N+1);
    P[0] = 1;
    rep(i,N){
        mx = mx*2 + 3;
        P[i+1]= P[i]*2 + 1;
        //BG = "B" + BG + "P" + BG + "B";
        //cout<<BG<<endl;

    }
    ll nmx = mx;
    ll nx = X;
    ll nl = N;
    ll ans = 0;
    while(1){
        if(nmx == nx){
            ans += P[nl];
            //cout<<"a"<<endl;
            break;
        }else if(nx==(nmx+1)/2){
            ans += P[nl-1]+1;
            //cout<<"b"<<endl;
            break;
        }else if(nx == 0){
            //cout<<"c"<<endl;
            break;
        }else if(nx > (nmx+1)/2){
            //cout<<"d"<<endl;
            ans += P[nl-1]+1;
            nx -= (nmx-1)/2;
        }else{
            //cout<<"e"<<endl;
        }

        nmx = (nmx-3)/2;
        nl--;
        nx--;
 
    }
    
    cout << ans << endl;


    return 0;
    

}