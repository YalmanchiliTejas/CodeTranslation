#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    rep(i,n) cin>>h[i];
    int cnt=0,m=0;
    rep(i,n){
        if(h[i]>=m){
            cnt++;
        }
        m=max(m,h[i]);
    }
    cout<<cnt<<endl;
    return 0;
}