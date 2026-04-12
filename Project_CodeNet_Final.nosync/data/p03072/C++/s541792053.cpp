#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,hi,ans;
    hi = 0;
    ans = 0;
    cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec.at(i);
    }
    for(int i=0;i<n;i++){
        if(hi <= vec.at(i)){
            ans ++;
            hi = vec.at(i);
        }
    }
    cout << ans << endl;
}