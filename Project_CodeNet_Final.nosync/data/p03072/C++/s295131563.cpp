#include<bits/stdc++.h>
//#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    int count=0;
    int MaX=h[0];
    for(int i=1;i<n;i++){
        if(MaX>h[i]) continue;
        count++;
        MaX=max(MaX,h[i]);
    }
    cout << count+1<< endl;
    return 0;
}