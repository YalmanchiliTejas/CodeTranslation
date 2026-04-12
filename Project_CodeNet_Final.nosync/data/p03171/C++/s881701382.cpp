# 1 "l.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "l.cpp"
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 1
       
# 12 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/bits/stdc++.h" 1
 #include <bits/stdc++.h>
# 13 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/assoc_container.hpp" 1
 #include <ext/pb_ds/assoc_container.hpp>
# 14 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/tree_policy.hpp" 1
 #include <ext/pb_ds/tree_policy.hpp>
# 15 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2







using namespace std;
using namespace __gnu_pbds;

using ii = pair<long long, long long>;
using vi = vector<long long>;
using vd = vector<long double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvb = vector<vb>;
using vvii = vector<vii>;
# 50 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
inline long long mod(const long long n, const long long m = ((long long)1e9+7)){
    return (n%m + m)%m;
}

/**
 * Euclidean GCD.
 *
 * Time Complexity: O(log(min(a, b))).
 * Space Complexity: O(log(min(a, b))).
 */
long long gcd(const long long a, const long long b){
    if(a < 0 or b < 0)
        return gcd(abs(a), abs(b));
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

/**
 * Euclidean derivated LCM.
 *
 * Time Complexity: O(log(min(a, b))).
 * Space Complexity: O(log(min(a, b))).
 */
long long lcm(const long long a, const long long b){
    // same as a*b/gcd(a, b) but avoiding overflow.
    return a/gcd(a, b)*b;
}
# 2 "l.cpp" 2

long long dp[2][(long long)3e3][(long long)3e3];
bool dp_aux[2][(long long)3e3][(long long)3e3];
vi arr;

long long solve(long long i, long long j, long long cur){
    if(j < i)
        return 0;
    if(dp_aux[cur][i][j])
        return dp[cur][i][j];
    dp_aux[cur][i][j] = true;
    if(cur == 0){
        return dp[cur][i][j] = max(
            arr[i] + solve(i+1, j, 1),
            arr[j] + solve(i, j-1, 1)
        );
    }
    else{
        return dp[cur][i][j] = min(
            - arr[i] + solve(i+1, j, 0),
            - arr[j] + solve(i, j-1, 0)
        );
    }
}

int32_t main(){
    (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
    long long n;
    cin >> n;
    arr.resize(n);
    for(long long &i:arr)
        cin >> i;
    cout << solve(0, n-1, 0) << "\n";
    return 0;
}
