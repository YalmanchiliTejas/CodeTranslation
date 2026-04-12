#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<char,int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll INF = LONG_LONG_MAX;
const int MAXN = 1e5+200;
const int mod = 1e9 +7;

string digits;
int d;
int n;
int dp[10010][2][110];  // idx - menor - sum

int go(int idx, int menor, int sum){
    if(idx==n) return (sum==0);
    int &r = dp[idx][menor][sum];
    if(r!=-1) return r;
    r= 0;
    int k= ((!menor) ? digits[idx]-'0' : 9);
    for(int i= 0; i<= k; ++i){
        if(k==i && !menor){
            r+= go(idx+1, menor, (sum+i)%d);
        }else{
            r+= go(idx+1, 1, (sum+ i)%d);
        }
        r%=mod;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>> digits>> d;
    memset(dp, -1, sizeof dp);
    n= digits.size();
    cout<<(go(0,0,0)-1+mod)%mod<<el;
}

