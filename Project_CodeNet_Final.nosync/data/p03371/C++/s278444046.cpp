#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(obj) (obj).begin(),(obj).end()

int main(){
    vector<int> a(5);
    rep(i,5)cin>>a.at(i);
    int mil;
    int l=max(a.at(3),a.at(4));
    for(int i=0;i<=l;i++){
        int k=max(0,(a.at(3)-i));
        int j=max(0,(a.at(4)-i));
        int tmp=a.at(0)*k+a.at(1)*j+a.at(2)*i*2;
        if((tmp<mil)||(i==0))mil=tmp;
    }
    cout<<mil<<endl;
    return 0;
}
