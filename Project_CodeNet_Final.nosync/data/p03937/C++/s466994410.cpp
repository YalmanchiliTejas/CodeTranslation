#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iomanip>
#include <tuple>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll INF=1LL<<60;
char a[10][10];

int main(){
    ll h,w;
    cin>>h>>w;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++)cin>>a[i][j];
    }
    string ans="Possible";
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(a[i][j]=='#'){
                if(0<=i-1 && 0<=j-1 && a[i-1][j]=='#' && a[i][j-1]=='#')ans="Impossible";
                if(0<=i+1 && 0<=j+1 && a[i+1][j]=='#' && a[i][j+1]=='#')ans="Impossible";
            }
        }
    }
    cout<<ans<<endl;
}
 
   