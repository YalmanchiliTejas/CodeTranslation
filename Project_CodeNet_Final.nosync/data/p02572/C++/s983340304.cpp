#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, i, j, ans=0, pro, tas;
    cin >> n;
    vector<long long> a(n), rui(n+1);
    rui.at(0)=0;
    for(i=0;i<n;i++){
        cin >> a.at(i);
        rui.at(i+1)=rui.at(i)+a.at(i);
        rui.at(i+1);
        
    }
    for(i=0;i<n-1;i++){
        tas = (rui.at(n)-rui.at(i+1));
        tas%=1000000007;
        if(tas<0) tas+=1000000007;
        pro=a.at(i)*tas;
        pro%=1000000007;
        ans+=pro;
        ans%=1000000007;
    }

    cout << ans <<endl;
}