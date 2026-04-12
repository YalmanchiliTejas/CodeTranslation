#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <random>
#include <cassert>
#include <numeric>
#define ll long long int
#define LL unsigned long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;



int main() {
    int n; cin >> n;

    map<char,int> mp[n];
    string l;
    rep(i,n){
        string s; cin >> s;
        int m = s.size();
        rep(j,m){
            mp[i][s[j]]++;
        }
        l = s;
    }
    int t = l.size();
    string ans = "";
    vector<char> c(t);
    rep(i,t) c[i] = l[i];
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    rep(i,c.size()){
        int ma = 1000;
        rep(j,n){
            ma = min(ma,mp[j][c[i]]);
        }
        rep(j,ma) ans += c[i];
    }
    cout << ans << endl;


}