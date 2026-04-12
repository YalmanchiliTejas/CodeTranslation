#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    int n;
    cin>>n;
    int h[n];
    int ans = 1;
    rep(i,0,n-1) cin>>h[i];
    int hoge = h[0];
    rep(i,1,n-1){
        if(hoge<=h[i]){
            ans++;
            hoge = h[i];
        } 
    }
    cout<<ans<<endl;
    return 0;
}