#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<tuple>
#include<utility>
#include<cctype>
#include<climits>
#include<map>
#include<queue>
#include<functional>

using namespace std;
template<class T> void chmax(T& a, T b) {if(a < b){a=b;}}
template<class T> void chmin(T& a, T b) {if(a > b){a=b;}}

#define REP(i,a,n) for(int i=a;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define ENT "\n"
#define REV(v) reverse(v.begin(),v.end())
#define SRTV(v) sort(v.begin(),v.end())
#define SRTA(a,n) sort(a,a+n)
#define MOD 1000000007

typedef long long ll;
typedef tuple<int,int,bool> Tb;

int atcoder(){
    //入力
    int x,y,z;
    cin >> x >> y >> z;
    //処理
    //出力
    cout << (x-z)/(y+z) << ENT;
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    atcoder();
    return 0;
}
