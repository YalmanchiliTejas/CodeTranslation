#include "bits/stdc++.h"
#define rep(i,a,n) for(int i = a;i < n;i++)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main(){
    int n,cnt = 0;
    cin >> n;
    int a[n];
    vector<int> yakusuu;
    
    rep(i,0,n){
        cin >> a[i];    
    }
    
    sort(a,a+n);
    
    rep(i,1,sqrt(a[n-1])+1){
        if(!(a[n-1] % i)){
            yakusuu.push_back(i);
            yakusuu.push_back(a[n-1]/i);
        }
    }
    
    sort(yakusuu.begin(),yakusuu.end());
    
    rep(i,0,n-1){
        rep(j,0,yakusuu.size()){
            if(a[i] <= yakusuu[j]){
                cnt += yakusuu[j]-a[i];
                break;
            }
        }
    }
    cout << cnt << endl;
}
