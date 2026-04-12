#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;

int A,B,C,X,Y;

int main(){
    cin>>A>>B>>C>>X>>Y;

    int ans=1001001001;
    rep(i,max(X,Y)+1){
        int x=max(0,X-i);
        int y=max(0,Y-i);
        int res=A*x+B*y+2*C*i;
        ans=min(ans,res);
    }

    cout<<ans<<endl;
}