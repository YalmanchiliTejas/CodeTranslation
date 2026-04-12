#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a.at(i);
    deque<int> d;
    rep(i,n){
        auto p = lower_bound(d.rbegin(), d.rend(),a[i]);
        if(p==d.rbegin()){
            d.push_back(a[i]);
        }else{
            p--;
            *p=a[i];
        }
    }
    cout<<d.size()<<endl;
}
//lower_boundがよくわからない。あとイテレータのクラスも