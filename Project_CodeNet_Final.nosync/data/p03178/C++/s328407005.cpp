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
#define fuck(x) cout << #x << " : " << x << endl;
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

const int mod = 1e9 + 7;

int32_t SALI()
{
    string s; int n,d; cin >> s >> d; n = s.size();

    int dp[n+2][d];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i < n; i++){ // i raghami
        for(int dg = 0; dg < 10; dg++){
            for(int j = 0; j < d; j++){ // k mod= j - dg
                dp[i][j] += dp[i-1][ ((((j-dg)%d)+d)%d) ];
                dp[i][j] %= mod;
            }

        }
    }
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s[i]-'0'; j++){ // x + sum + j mod= 0
            ans += dp[n-i-1][ (((-1*(sum+j))%d)+d)%d];
            ans %= mod;
        }
        sum += s[i]-'0';
    }
    if(d != 1) ans = (ans-1+mod)%mod;
    if(sum % d == 0 && d != 1) ans = (ans+1)%mod;
    cout << ans << endl;
}




/**< WRITEN BY ALI ADELKHAH */

