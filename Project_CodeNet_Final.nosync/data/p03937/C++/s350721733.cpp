#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007

using namespace std;

int main(){
    lli h,w,count=0;
    char a;
    string ans;
    lli i,j;
    cin>>h>>w;
    rep(i,0,h){
        rep(j,0,w){
            cin>>a;
            if(a=='#'){
                count++;
            }
        }
    }
    if(count==w+h-1){
        ans="Possible";
    }
    else{
        ans="Impossible";
    }
    cout<<ans<<endl;
}

