#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main(){
    int n;
    cin >> n;
    VEC(ll, a, n);
    sort(ALL(a));

    if(n % 2 == 0){
        int l = 0, r = n - 1;
        ll sum = 0;
        rep(i, n - 2){
            if(i % 2 == 0){
                sum += (2 * a[r]);
                r--;
            }
            else {
                sum -= (2 * a[l]);
                l++;
            }
        }
        sum += (a[r] - a[l]);
        cout << sum << endl;
    }
    else {
        int l = 0, r = n - 1;
        ll res = 0;
        ll sum = 0;
        //端がマイナス
        rep(i, n - 2){
            if(i % 2 == 0){
                sum += (2 * a[r]);
                r--;
            }
            else {
                sum -= (2 * a[l]);
                l++;
            }
        }
        sum -= (a[r] + a[l]);
        res = sum;

        //端がプラス
        sum = 0;
        r = n - 1;
        l = 0;
        rep(i, n - 2){
            if(i % 2 == 1){
                sum += (2 * a[r]);
                r--;
            }
            else {
                sum -= (2 * a[l]);
                l++;
            }
        }
        sum += (a[r] + a[l]);
        res = max(res, sum);
        cout << res << endl;
    }
}