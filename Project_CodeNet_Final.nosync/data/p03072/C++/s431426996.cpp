#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int inn[n];
    int maxx=0;
    int ans=0;
    for(int i=0; i<n; ++i){
        cin >> inn[i];
        if(inn[i] >= maxx){
            maxx = inn[i];
            ans++;
        }
    }
    cout << ans << endl;
}
