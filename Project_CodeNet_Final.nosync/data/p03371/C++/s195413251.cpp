#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    int num = min(X,Y);
    if(A+B>C*2){
        ans+=num*2*C;
        X-=num;
        Y-=num;
    }else{
        ans+=num*(A+B);
        X-=num;
        Y-=num;
    }
    if(A>C*2){
        ans+=2*X*C;
    }else{
        ans+=X*A;
    }
    if(B>C*2){
        ans+=2*Y*C;
    }else{
        ans+=Y*B;
    }
    cout << ans << endl;
    return 0;
}