#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<int> v;
    rep(i,n){
        int t = a[i];
        for(int j = 2; j*j <= t; j++)if(t%j == 0){
            v.push_back(j);
            while(t%j == 0)t /= j;
        }
        if(t > 1)v.push_back(t);
    }
    sort(v.begin(),v.end());
    //rep(i,v.size())cout << " " << v[i];cout << endl;
    long long ans = 0;
    rep(i,v.size()){
        long long sum = 0;
        rep(j,n)if(a[j] % v[i] == 0)sum += a[j];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

