#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int h,w;
    cin>>h>>w;
    vector<string> p(h);
    rep(i,h) cin>>p[i];
    vector<int> cn;
    rep(i,h){
        bool che=true;
        rep(j,w) if(p[i][j]=='#') che=false;
        if(che) cn.push_back(i);
    }
    sort(etob(cn));
    for(auto& v: cn){
        p.erase(p.begin()+v);
    }
    cn.clear();
    rep(i,w){
        bool che=true;
        int a=p.size();
        rep(j,a) if(p[j][i]=='#') che=false;
        if(che) cn.push_back(i);
    }
    sort(etob(cn));
    for(auto& v: cn){
        int a=p.size();
        rep(i,a) p[i].erase(p[i].begin()+v);
    }
    for(auto& v:p) cout<<v<<endl;
    return 0;
}