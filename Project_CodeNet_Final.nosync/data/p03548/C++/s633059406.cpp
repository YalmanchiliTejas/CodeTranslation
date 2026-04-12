#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    int X,Y,Z;cin>>X>>Y>>Z;
    X-=Z;
    cout<<X/(Y+Z)<<endl;
}