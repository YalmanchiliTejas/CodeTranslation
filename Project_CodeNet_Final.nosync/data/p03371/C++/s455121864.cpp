#include "bits/stdc++.h"
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
using ull = unsigned long long;
using ll = long long;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;


int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int sum=A*X+B*Y;
    int ans=sum;
    int x=X,y=Y;
    for(int i=1; i<=max(X,Y); i++){
        int res=sum;
        res += C*2;
        if(x>0){
            res -= A;
        }
        if(y>0){
            res -= B;
        }
        ans = min(ans,res);
        sum = res;
        x--;
        y--;
    }
    cout << ans << endl;
    return 0;
}