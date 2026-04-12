#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;cin >> n;
    vector<LL> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    LL ans = 0;
    for(int k = 2;k < 50000;k++){
        LL t = 0;
        for(int i = 0 ;i < n;i++){
            if(v[i]%k==0) t += v[i];
        }
        ans = max(t,ans);
    }
    for(int i=0;i<n;i++){
        if(v[i]==1) continue;
        LL t = 0;
        for(int j=0;j<n;j++){
            if(v[j]%v[i]==0) t += v[j];
        }
        ans = max(t,ans);
    }
    cout << ans << endl;
    return 0;
}

            

