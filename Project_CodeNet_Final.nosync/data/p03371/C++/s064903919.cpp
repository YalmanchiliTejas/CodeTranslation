#include<bits/stdc++.h>
using namespace std;
const int INF=2E9;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int ans=INF;
    for(int i=0;i<=2*max(X,Y);i+=2){
        ans=min(ans,A*max(X-i/2,0)+B*max(Y-i/2,0)+C*i);
    }
    cout << ans << endl;
    return 0;
}
