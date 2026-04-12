#include <bits/stdc++.h>
using namespace std;
int64_t saiki(int64_t n, int64_t x, vector<int64_t> p){
    int64_t ans;
    if (x == 1) {
        if (n == 0) ans = 1;
        else ans = 0;
        return ans;
    }
    if (x > 1 && x < (pow(2, n + 1) - 1)){
        //cout << "jj" << endl;
        ans = saiki(n - 1, x - 1, p);
    }
    if (x == pow(2, n + 1) - 1){
        //cout << "ii" << endl;
        ans = p.at(n - 1) + 1;
    }
    if (x > pow(2, n + 1) - 1 && x < pow(2, n + 2) - 3){
        ans = p.at(n - 1) + 1 + saiki(n - 1, x - (pow(2, n + 1) - 1), p);
    }
    if (x == pow(2, n + 2) - 3){
        ans = p.at(n);
    }
    return ans;
    
}
int main(){
    int64_t N, X;
    cin >> N >> X;
    vector<int64_t> p(N + 2, 1);
    for (int i = 0; i <= N; i++){
        p.at(i + 1) = 2 * p.at(i) + 1;
    }
    int64_t ans = saiki(N, X, p);
    cout << ans << endl;
}