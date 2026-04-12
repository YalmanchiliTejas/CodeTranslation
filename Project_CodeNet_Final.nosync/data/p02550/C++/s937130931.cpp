#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,x,m;
    cin>>n>>x>>m;
    if(x==0){cout<<0;return 0;}
    if(x==1){cout<<n;return 0;}
    ll summ = 0;ll count = 0;
    set<ll> s;
    //unordered_map<ll,ll> m;
    vector<ll> v;
    while(x){
        v.push_back(x);
        s.insert(x);
        summ+=x;
        count++;
        if(count==n)break;
        x = (x*x)%m;
        if(s.find(x)!=s.end()){
            break;
        }
    }
    if(x==0){cout<<summ<<endl;return 0;}
    if(count==n){cout<<summ<<endl;return 0;}
    int i;
    for( i=0;i<v.size();++i){
        if(v[i]==x)break;
    }
    ll repeats = v.size()-i;
    ll extra_summ = 0;
    for(int j=i;j<v.size();++j){
        extra_summ += v[j];
    }
    ll leftt = n - count;
    ll soul = leftt/repeats;    //extraacase
    summ = summ + soul*extra_summ;
    if(leftt%repeats!=0){
        ll special = leftt%repeats;
        for(int j=0;j<special;++j){
            summ = summ + v[j+i];
        }
    }
    cout<<summ<<endl;
    return 0;


    

}

