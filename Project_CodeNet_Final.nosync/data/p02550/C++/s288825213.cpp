#include <bits/stdc++.h>
#define Rep(i,j,n) for(int i=j; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    ll n,x,m; cin >> n >> x >> m;
    ll ans=0;
    vector<ll> lop;
    unordered_map<int,int> u;
    //u[x]++;
    //n--;
    //lop.push_back(x);
    while(n-->0){
        x%=m;
        u[x]++;
        lop.push_back(x);
        if(u[x]>=2) break;
        ans+=x;
        x*=x;
    }
    if(n<=0){
        cout << ans << endl;
        return 0;
    }
    int index,index2;
    index=-1;
    index2=lop.size()-2;
    rep(i,lop.size()){
        if(lop[i]==x){
            if(index==-1){
                index=i;
                break;
            }
        }
    }

    ll lsum=0;
    ll leni=index2-index+1;
    rep(i,leni){
        lsum+=lop[index+i];
    }

    ans+=lsum*(n/leni);
    n-=(n/(leni))*leni;

    while(n-->=0) ans+=lop[index++];
    cout << ans << endl;

    return 0;
}