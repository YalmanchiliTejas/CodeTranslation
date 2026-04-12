#include <bits/stdc++.h>
using namespace std;

int main(){
    int X,Y,Z;
    cin >> X >> Y >> Z;
    int cnt=Z,ans=-1;
    while(cnt<=X){
        ans++;
        cnt+=Y+Z;
    }
    cout << ans << endl;
}