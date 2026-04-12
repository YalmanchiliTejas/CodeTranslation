//  Created by conan1024hao in 2019.
//  Copyright © 2019 conan1024hao. All rights reserved.
//  専用ライブラリです、自由にコピーして構いません。
//  感谢看我的代码！Wechat:conan1024hao QQ:810396815
#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define INF 10e16
#define MOD 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
//using Int=int_fast64_t;
typedef long long int ll;
typedef pair<ll,ll>Pll;
typedef pair<int,int>Pin;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
char dir[4]={'u','l','d','r'};
ll cmp1(pair<ll,string>a,pair<ll,string> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se<b.se;
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int main(){//問題をちゃんと見ろ!!!!!!!!!!!!!!!!!      llか??????????
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    int h,w;cin>>h>>w;
    char a[110][110];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    vector<int>row;
    for(int i=0;i<h;i++){
        int abc=1;
        for(int j=0;j<w;j++)
            if(a[i][j]=='#')
                abc=0;
        if(abc==1)
            row.pb(i);
    }
    vector<int>rei;
    for(int i=0;i<w;i++){
        int abc=1;
        for(int j=0;j<h;j++)
            if(a[j][i]=='#')
                abc=0;
        if(abc==1)
            rei.pb(i);
    }
    int ro=0,re=0;
    for(int i=0;i<h;i++){
        if(ro<siz(row))
        if(i==row[ro]){
            ro++;
            continue;
        }
        for(int j=0;j<w;j++){
            //cout<<j<<" "<<rei[re]<<endl;
            if(re<siz(rei))
            if(j==rei[re]){
                re++;
                continue;
            }
            cout<<a[i][j];
        }
        re=0;
        cout<<endl;
    }
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------
