#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

const ll MOD = 1e+9+7;
const int INF = 1e+9+7;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int ans=INF;
    int money=0;
    rep(i,max(X,Y)+1){
        money= max(0,A*(X-i))+max(0,B*(Y-i))+2*i*C;
        ans=min(ans,money);
    }
    cout << ans << endl;
}