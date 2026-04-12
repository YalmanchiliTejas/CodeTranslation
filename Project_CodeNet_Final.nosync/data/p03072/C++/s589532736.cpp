#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,cnt=0,maks=0;
    cin >> n;
    int k[n+1];
    for(int i=0;i<n;i++) {
        cin >> k[i];
        if(k[i]>=maks) maks = k[i],cnt++;


    }

    cout << cnt;
}
