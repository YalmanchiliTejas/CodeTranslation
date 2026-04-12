#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 1000000000;
    for(int i = 0;i < 100001;i++){
        int sum = c*i*2+a*max(0,x-i)+b*max(0,y-i);
        ans = min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}