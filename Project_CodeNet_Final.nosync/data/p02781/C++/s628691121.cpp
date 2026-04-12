#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

ll comb(ll a,ll b){
    if(a<0||b<0||a<b) return 0;
    ll c=1;
    fr(i,b) c*=a-i;
    Fr(i,b) c/=i;
    return c;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    istream& in(cin);
    ostream& out(cout);
    string n;
    int k;
    in>>n>>k;
    ll ans{},p[]={1,9,81,729};
    int m=n.length(),cnt{k};
    fr(i,m){
        if(n[i]-'0'){
            ans+=comb(m-i-1,cnt)*p[cnt];
            if(cnt) fr(j,n[i]-'1') ans+=comb(m-i-1,cnt-1)*p[cnt-1];
            --cnt;
            if(!cnt){
                ++ans;
                break;
            }
        }
    }
    cout<<ans<<endl;
}