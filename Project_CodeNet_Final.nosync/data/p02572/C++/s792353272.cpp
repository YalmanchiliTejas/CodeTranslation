#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long add(long long a, long long b) {
    long long res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

long long sub(long long a, long long b) {
    long long res = a - b + mod;
    if (res >= mod) res -= mod;
    return res;
}

long long mul(long long a, long long b) {
    return (((a % mod) * (b % mod)) % mod);
}

long long gcd(long long x, long long y){
    if(y == 0){
        return x;
    }
    if(x > y){
         return gcd(y, x % y);
    }
    else{
         return gcd(x, y % x);
    }
}

void dfs(vector<vector<int>> &v, vector<int> &visited, int node, int &ans){
    if(visited[node]){
        return;
    }
    visited[node] = 1;
    ans++;
    for(auto i : v[node]){
        dfs(v, visited, i, ans);
    }
}

/*bool good(vector<int> &v, int d, int mid){
    vector<int> p(v.size());
    p[0] = v[0] - mid;
    for(int i = 1;i < v.size();i++){
        p[i] = p[i - 1] + (v[i] - mid);
    }
    vector<int> m(v.size());
    m[0] = p[0];
    int mi = m[0];
    for(int i = 1;i < v.size();i++){
        mi = min(mi, p[i]);
        m[i] = mi;
    }
    for(int r = 0;r < v.size();r++){
        if(r - d > 0){
            if(m[r - d - 1] <= p[r]){
                L = r - d;
                R = r;
                return true;
            }
        }
    }
    return false;
}*/

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    long long sum = 0,
        ans = 0;
    for(int i = 0;i < n;i++){
        cin >> v[i];
        ans += (v[i] * sum) % mod;
        ans %= mod;
        sum += v[i];
        sum %= mod;
    }
    ans %= mod;
    cout << ans << endl;











    /*int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    int l = -1,
        r = 101;
    while(r > l + 1){
        int mid = (l + r) / 2;
        if(good(v, d, mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << L + 1 << " " << R + 1<< endl;
    cout << l << endl;*/
}
/*
5 2
-1 -2 -3 4 5
2 3
4

-3 -2 -1 4 5
2 3
5 + (-3) = 2
4 + -2 = 2
ans = 4

-3 -2 -1 4 5
3 2
5 + -3 = 2
4 + -1 = 3
ans = 5
*/
