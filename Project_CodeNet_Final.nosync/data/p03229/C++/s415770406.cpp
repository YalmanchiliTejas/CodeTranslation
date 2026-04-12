#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    
    long long res = 0;
    long long res1 = 0, res2 = 0;
    if(n%2){
        rep(i, (n-1)/2){
            res1 += -2*a.at(i);
        }
        res1 += a.at((n-1)/2);
        res1 += a.at((n-1)/2 + 1);
        for(int i = (n-1)/2 + 2; i < n; i++){
            res1 += 2*a.at(i);
        }
        
        rep(i, (n-1)/2 - 1){
            res2 += -2*a.at(i);
        }
        res2 += a.at((n-1)/2 - 1)*-1;
        res2 += a.at((n-1)/2)*-1;
        for(int i = (n-1)/2 + 1; i < n; i++){
            res2 += 2*a.at(i);
        }
        
        res = max(res1, res2);
    } else {
        rep(i, (n-2)/2){
            res += -2*a.at(i);
        }
        res += a.at((n-2)/2)*-1;
        res += a.at((n-2)/2 + 1);
        for(int i = (n-2)/2 + 2; i < n; i++){
            res += 2*a.at(i);
        }
    }
    
    cout << res << endl;
    return 0;
}