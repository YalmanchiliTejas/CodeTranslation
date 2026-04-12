#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,t=0,ans=1;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a.at(i);
    }
    t=a.at(0);
    for (int i=1;i<n;i++){
        if (a.at(i)>=t) {ans++;t=a.at(i);}
    }
    cout << ans << endl;
}
