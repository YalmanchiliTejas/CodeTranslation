#line 1 "code.cpp"
#include<bits/stdc++.h>
using namespace std;
using lint=long long;

lint n,x,m;

//最初にidxにいた人はk回後にv[idx].firstにいる
//最初にidxにいた人はk回後にv[idx].second点手に入れた
//というように配列を持ちます
//k1回後の情報とk2回後の情報からk1+k2回後の情報が手を手に入れる関数がfです

vector<pair<lint,lint>> f(const vector<pair<lint,lint>>&s,const vector<pair<lint,lint>>&t){
    vector<pair<lint,lint>>ret(m);
    for(int i=0;i<m;++i){
        ret[i]=make_pair(t[s[i].first].first,s[i].second+t[s[i].first].second);
    }
    return ret;
}

int main(){
    cin>>n>>x>>m;
    vector<pair<lint,lint>>v(m),ans(m);
    for(lint i=0;i<m;++i){
        ans[i]=make_pair(i,0);
        v[i]=make_pair(i*i%m,i);
    }
    while(n){
        if(n%2)ans=f(ans,v);
        v=f(v,v);
        n/=2;
    }
    cout<<ans[x].second<<endl;
}
