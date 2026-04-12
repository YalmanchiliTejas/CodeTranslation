#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;



int main(){
    int N;
    cin >> N;
    LL mi=LINF,rmi=LINF,mx=-1,rmx=-1;
    vector<P> v;
    for (int i = 0; i < N; i++) {
        LL x,y;
        cin >> x >> y;
        if(y>x) swap(x,y);
        mi=min(mi,y);
        rmi=min(rmi,x);
        mx=max(mx,x);
        rmx=max(rmx,y);
        v.pb({x,y});
    }
    LL ans=(mx-rmi)*(rmx-mi);
    sort(RALL(v));
    LL t=mx-mi;
    LL limi=-1;
    for (int i = 0; i < N-1; i++) {
        if(v[i].fs<limi) break;
        rmi=min(rmi,v[i].sc);
        if(v[i].fs>v[i+1].fs){
            mx=max({v[i].sc,v[i+1].fs,limi});
        }
        ans=min(ans,t*(mx-rmi));
        limi=max(limi,v[i].sc);
    }
    cout << ans << endl;
    return 0;
}

