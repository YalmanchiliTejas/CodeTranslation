#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n;i++)
#define repf(i, a, b) for (int i = (int)a; i < (int)b;i++)
#define repv(x, arr) for (auto& x:arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a,b) make_pair(a,b)
#define op(i) cout << (i) << endl;
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

const ll mod = 1e9 + 7;

char need(char a,char b,char s){
    if (a==b){
        if (s=='o'){
            return 'S';
        }
        else{
            return 'W';
        }
    }
    else {
        if (s=='o'){
            return 'W';
        }
        else{
            return 'S';
        }
    }
}

string check(char a,char b,ll N,string S){
    vector<char> ans(N);
    ans[0] = a;
    ans[1] = b;
    repf(i, 2, N)
    {
        ans[i] = need(ans[i - 2], ans[i - 1], S[i - 1]);
    }
    if (ans[0]==need(ans[N-2],ans[N-1],S[N-1]) && ans[1]==need(ans[N-1],ans[0],S[0])){
        string ansS = "";
        rep(i, N)
        {
            ansS += ans[i];
        }
        return ansS;
    }
    return "-1";
}

int main(){
    ll N;
    string S;
    cin >> N >> S;
    vector<char> ans(N);
    string ansS;
    ansS = check('S', 'S', N, S);
    if (ansS != "-1")
    {
        cout << ansS << endl;
        return 0;
    }
    ansS = check('S', 'W', N, S);
    if (ansS != "-1")
    {
        cout << ansS << endl;
        return 0;
    }
    ansS = check('W', 'S', N, S);
    if (ansS != "-1")
    {
        cout << ansS << endl;
        return 0;
    }
    ansS = check('W', 'W', N, S);
    if (ansS != "-1")
    {
        cout << ansS<<endl;
        return 0;
    }
    cout << -1 << endl;
}