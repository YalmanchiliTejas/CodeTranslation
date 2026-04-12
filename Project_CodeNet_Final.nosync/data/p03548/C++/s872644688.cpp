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
    int x,y,z;
    cin>>x>>y>>z;
    int ans=0;
    x = x - 2*z;
    if(x>=y){
        x = x - y;
        //ans++;
        while(1){
            if(x>=0){
                ans++;
                x = x - (y+z);
            }
            else break;
        }
    } 
    cout<<ans<<endl;
    return 0;
}