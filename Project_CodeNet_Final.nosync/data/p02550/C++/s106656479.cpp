#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
typedef pair<int,int> P;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll MOD=1e9+7;
static const int MAX = 100;
static const int INF = (1<<23);
template<class T> T gcd(T a, T b){return b? gcd(b,a%b) : a;}
template<class T> T lcm(T a,T b){return a / gcd(a,b)*b;}

int main(){

    ll n,x,m;
    cin>>n>>x>>m;
    set<ll> s;
    ll a = x;
    s.insert(a);
    vector<ll> v;
    v.push_back(a);
    ll i=1;
    ll sum = a;

    while(true){
        if(i==n){
            cout<<sum<<endl;
            return 0;
        }
        a = ((a%m)*(a%m))%m;
        if(s.find(a)!=s.end()){break;}
        else{
            v.push_back(a);
            s.insert(a);
            sum+=a;
        }
        i++;
    }



    n-=v.size();
    ll ans = sum;
    int lpind = 0;
    ll nlp = 0;
    while(v[lpind]!=a){
        nlp+=v[lpind];
        lpind++;
    }
    ll looplen = v.size()-lpind;
    ans+=(n/looplen)*(sum-nlp);
    n%=looplen;
    for(int i=0;i<n;i++){
        ans+=v[i+lpind];
    }
    cout<<ans<<endl;






return 0;
}
