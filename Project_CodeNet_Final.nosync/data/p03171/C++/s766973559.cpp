/*
___mennat khoday ra azz o va jall ke taatash mojebe ghorbat ast o be shokr andarash mazide nemat.
___har nafasi ke foro miravad momedde hayatast o chon bar miayad mofarrahe zat.
___pas dar har nafasi 2 nemat mojod ast o bar har nematy shokry vajeb.

___az dast o zabane ke barayad ?
___kaz ohdeye shokrash be dar ayad !


___man be to dami gharar natvanam kard
___va ehsane to ra shomar natvanam kard
####################
___gar bar tane man zaban shavad har moyee
___yek shokre to az hezar natvanam kard

*/

#include <bits/stdc++.h>

#define pb push_back
#define SALI main
#define left(x) ((x)*2)
#define right(x) (((x)*2)+1)
#define fuck(x) cout << #x << " : " << x << "   ";
#define findLowVec(v,x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define findUpVec(v,x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define findLowArr(a,n,x) (lower_bound(a, a+n, x) - a)
#define findUpArr(a,n,x) (upper_bound(a, a+n, x) - a)
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p)
{return out << "(" << p.first << ", " << p.second << ")";}

template<class A> ostream& operator <<(ostream& out, const vector<A> &v)
{out << "[";for(int i = 0; i < v.size(); i++) {if(i) out << ", ";out << v[i];}return out << "]";}

template<class A,class B> ostream& operator <<(ostream& out, const set<A,B> &s)
{out << "[";for(auto i = s.begin(); i != s.end(); i++) {out << ", ";out << *i;}return out << "]";}

template<class A> ostream& operator <<(ostream& out, const set<A> &s)
{out << "[";for(auto i = s.begin(); i != s.end(); i++) {out << ", ";out << *i;}return out << "]";}

const int inf = 1LL << 60;
const int N = 3000 + 10;
int dp[2][N][N]; // 0 try to max x-y  and 1 try to min x-y   0 : x   ___  1 : y
int a[N];
int n;

int solve(int l, int r, int p)
{
    if(l == r){
        dp[p][l][r] = (p==0?1:-1) * a[l];
        return dp[p][l][r];
    }
    if(dp[p][l][r] != inf){
        return dp[p][l][r];
    }

    if(p == 0){
        dp[0][l][r] = max( solve(l+1,r,1) + a[l] , solve(l,r-1,1) + a[r]);
    }
    else{
        dp[1][l][r] = min( solve(l+1,r,0) - a[l] , solve(l,r-1,0) - a[r]);
    }
    return dp[p][l][r];
}

int32_t SALI()
{
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dp[0][i][j] = dp[1][i][j] = inf;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << solve(1,n,0);

}


/**< WRITEN BY ALI ADELKHAH */

