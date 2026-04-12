#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,i,j,ans=0,yes;
    cin >> n;
    vector<int> h(n);
    for(i=0;i<n;i++) cin >> h.at(i);
    for(i=0;i<n;i++){
        yes=1;
        for(j=0;j<i;j++){
            if(h.at(j)>h.at(i))yes=0;
        }
        ans += yes;
    }
    cout << ans << endl;
    return 0;
}