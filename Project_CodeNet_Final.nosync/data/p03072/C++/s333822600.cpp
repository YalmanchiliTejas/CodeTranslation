#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int &x : v){
        cin >> x ;
    }
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;i++){
        sum[i] = max(sum[i-1],v[i-1]);
    }
    int cnt = 0 ;
    for(int i=1;i<=n;i++){
        if ( v[i-1] == sum[i] ){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0 ;
}
