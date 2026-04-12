#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long a[50];

bool check(){
    for(int i = 0;i < n;i++){
        if(a[i] >= n) return false;
    }
    return true;
}

int big(){
    int maxi = 0,maxn = 0;
    for(int i = 0;i < n;i++){
        if(a[i] > maxi){
            maxi = a[i];
            maxn = i;
        }
    }
    return maxn;
}

long long solve(){
    long long ans = 0;
    for(int i = 0;i < n;i++){
        if(a[i] > n*(n+1)){
            long long ki = a[i] / (n*(n+1));
            ans += n*(n+1)*(ki-1);
            a[i] -= n*(n+1)*(ki-1);
        }
    }
    while(true){
        if(check()) return ans;
        int k = big();
        for(int i = 0;i < n;i++) a[i]++;
        a[k] -= n+1;
        ans++;
    }
}

int main() {
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    cout << solve() << endl;
}
