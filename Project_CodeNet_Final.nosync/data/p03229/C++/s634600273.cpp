typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    sort(a.begin(),a.end());
    
    ll c1,c2,m1,m2;
    c1 = 1+(n%2==1);
    c2 = (n-2)/2;
    m1 = 1-(n%2==1);
    m2 = (n-2+1)/2;
    
    ll tmp = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if(i<m2){
           tmp += -2*a[i]; 
        }else if(i<m2+m1){
            tmp += -1*a[i];
        }else if(i<m2+m1+c1){
            tmp += 1*a[i];
        }else{
            tmp += 2*a[i];
        }
    }
    res = tmp;
    tmp = 0;
    
    for (int i = 0; i < n; i++) {
        if(i<c2){
           tmp += -2*a[i]; 
        }else if(i<c2+c1){
            tmp += -1*a[i];
        }else if(i<c2+c1+m1){
            tmp += 1*a[i];
        }else{
            tmp += 2*a[i];
        }
    }
    
    std::cout << max(res,tmp) << std::endl;
}
