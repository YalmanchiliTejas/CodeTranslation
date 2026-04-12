#include<bits/stdc++.h>
using namespace std;
using Int = long long;
Int K;
string s;
vector<vector<vector<vector<Int>>>>memo;
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
Int rec(int idx, int cnt, int num, bool tight){
    Int res = 0;
    if(idx + 1  == s.size()){
        //if(tight) cout << "tight" << endl;
        return (cnt + (num != 0) == K);
    }
    if(memo[idx][num][cnt][tight] != -1) return memo[idx][num][cnt][tight];
    if(tight){
        int lim = s[idx + 1] - '0';
        //cout << lim << endl;
        for(int i = 0; i <= lim; ++i){
            res += rec(idx + 1, cnt + (num != 0),i, tight && lim == i);
        }
    } else {
        for(int i = 0; i <= 9; ++i){
            res += rec(idx + 1, cnt + (num != 0),i, false);
        }
    }
    return memo[idx][num][cnt][tight] = res;
}
int main(){
    cin >> s;
    cin >> K;
    Int res = 0;
    memo = vectors(s.size(),10,s.size() + 10,2,-1LL);
    for(int i = 0; i <= s.front() - '0'; ++i){
        int num = s.front() - '0';
        res += rec(0,0,i, num == i);
    }
    cout << res << endl;
}
