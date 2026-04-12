#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef bitset<18> MASK;

#define ll long long
#define PI 3.14159265359
//#define x first
//#define y second
#define point pair<int,int>
#define clr(x, val)	memset((x), (val), sizeof(x))

//you don't know math, unless you can do math!
vector<int> num;
int dp[10009][100][2];
int md = 1e9 + 7;
int d;

int solve(int i, int mod, int smaller){
    if(i == num.size())
        return (mod == 0);

    int &ret = dp[i][mod][smaller];
    if(ret != -1)
        return ret;

    int mx;
    if(smaller)
        mx = 9;
    else
        mx = num[i];

    ret = 0;
    for(int k = 0; k <= mx; k++){
        ret += solve(i + 1, (mod + k)%d, smaller || (k < mx));
        ret %= md;
    }

    return ret;
}

int solve1(string s){
    num.clear();
    for(int i = 0; i < s.length(); i++)
        num.push_back(s[i] - '0');

    clr(dp, -1);
    return solve(0, 0, 0);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string h; cin>>h;
    cin>>d;

    cout<<(solve1(h) - 1 + md)%md;
}
