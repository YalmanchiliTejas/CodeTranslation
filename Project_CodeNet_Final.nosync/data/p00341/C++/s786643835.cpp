#include "bits/stdc++.h"
#define rep(i,a,n) for(int i = a;i < n;i++)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main(){
    int a[12],memo = 0,cnt = 0;
    
    rep(i,0,12){
        
        cin >> a[i];
    }
    
    sort(a,a+12);
    
    rep(i,1,12){
        cnt++;
        if(a[i-1] != a[i]){
            if(cnt % 4){
                cout << "no" << endl;
                return 0;
            }
            cnt = 0;
        }
    }
    
    cnt++;
    if(cnt % 4){
        cout << "no" << endl;
        return 0;
    }
    
    cout << "yes" << endl;
    
    return 0;
}
