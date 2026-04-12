#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    int n,ans=0;
    cin >> n;
    int x,m=0;
    for(int i=1;i<=n;i++){
        cin >> x;
        if(m<=x)    ans++;
        m = max(m,x);
    }
    cout << ans << endl;
    return 0;
}