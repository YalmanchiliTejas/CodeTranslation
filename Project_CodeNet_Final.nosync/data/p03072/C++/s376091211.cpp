#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,max; cin>>n>>max;
    int ans=1;
    for(int i=1; i<n; i++) {
        int h; cin>>h;
        if(max<=h) {
            ans++;
            max=h;
        }
    }
    cout << ans << endl;
}