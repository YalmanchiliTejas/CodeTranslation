#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, x, m, ans, i, pre, sum=0, nok, cnt=0;
    map<long long, long long > mp;
    cin >> n >> x >> m;
    pre=x;ans=x;
    for(i=2;i<=n;i++){
        ans+=(pre*pre)%m;
        if(((pre*pre)%m) == 0) break;
        pre=(pre*pre)%m;
        mp[pre]++;
        if(mp[pre]>1) break;
    }
    nok=n-i;
    if(nok>0){
        for(i=2;i<=n;i++){
            cnt++;
            sum=sum+(pre*pre)%m;
            if(((pre*pre)%m) == 0) break;
            pre=(pre*pre)%m;
            mp[pre]++;
            if(mp[pre]>2 && cnt!=0) break;
        }
        ans+=sum*(nok/cnt);
        nok-=(nok/cnt)*cnt;
        for(i=0;i<nok;i++){
            ans+=(pre*pre)%m;
            pre=(pre*pre)%m;
        }

    }
    cout << ans <<endl;
    return 0;
}