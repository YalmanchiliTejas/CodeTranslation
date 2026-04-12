#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> vp(51); 
vector<bool> cashed(51);

pair<ll,ll> burger1(int level){
    if(cashed.at(level)) return vp.at(level);
    pair<ll,ll> p;
    if(level == 0){
        p = {1,1};
    }else{
        auto lvm1 = burger1(level-1);
        p = {lvm1.first*2+3, lvm1.second*2+1};
    }
    vp.at(level) = p;
    cashed.at(level) = true;
    return p;
}

ll burger(int level, ll eat){
    if(level==0) {
        if(eat == 0) return 0;
        else return 1;
    }
    ll tot=0;
    ll rest = eat;
    if(rest <= 0) return tot;

    // top ban
    rest--;
    if(rest <= 0) return tot;
    
    // level-1
    if(rest < vp.at(level-1).first){
        return burger(level-1,rest) + tot;
    }
    rest -= vp.at(level-1).first;
    tot += vp.at(level-1).second;
    if(rest <= 0) return tot;

    // center pan
    rest--;
    tot++;
    if(rest <= 0) return tot;

    // level-1
    if(rest < vp.at(level-1).first){
        return burger(level-1,rest) + tot;
    }
    rest -= vp.at(level-1).first;
    tot += vp.at(level-1).second;
    
    return tot;
}

int main(){
    ll n,x;
    cin >> n >> x;
    burger1(n);
    // rep(i,n+1) cout << vp.at(i).second << endl;
    cout << burger(n,x) << endl;
    return 0;
}