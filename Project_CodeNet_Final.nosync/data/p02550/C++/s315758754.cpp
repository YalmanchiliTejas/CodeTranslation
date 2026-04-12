#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    long long N, X, M;
    cin >> N >> X >> M;
    vector<long long> cnt;
    cnt.push_back(X);
    set<long long> s;
    s.insert(X);
    int ind;
    while(1){
        X = X * X % M;
        if(s.count(X)) {
            for(int i = 0; i < (int)cnt.size(); i++){
                if(cnt[i] == X) ind = i;
            }
            break;
        }
        s.insert(X);
        cnt.push_back(X);
    }
    int n = cnt.size();
    long long ans = 0;
    if(N <= n){
        for(int i = 0; i < N; i++) ans += cnt[i];
    }
    else{
        if(cnt[n - 1] != 0){
            long long sum = 0;
            for(int i = ind; i < n; i++){
                sum += cnt[i];
            }
            long long t = n - ind;
            for(int i = 0; i < ind; i++) ans += cnt[i];
            ans += (N - ind) / t * sum;
            for(int i = ind; i < ind + (N - ind) % t; i++){
                ans += cnt[i];
            }
        }
        else{
            for(int i = 0; i < n; i++){
                ans += cnt[i];
            }
        }
    }
    cout << ans << endl;
}