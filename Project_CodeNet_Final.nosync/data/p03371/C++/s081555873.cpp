//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1<<30;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};



int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int a,b,ab,xa,xb;
    cin>>a>>b>>ab>>xa>>xb;
    int ans=1e9+7;
    int cnt=0;
    //abでmin(xa,xb)を買い、残りをa,bで
    if(xa>xb){
        cnt +=xb*ab*2;
        cnt +=(xa-xb)*a;
        ans =min(ans,cnt);
        cnt=0;
    }
    else{
        cnt=xa*ab*2+(xb-xa)*b;
        ans =min(ans,cnt);
        cnt=0;
    }
    //abで全部買う
    cnt=max(xa,xb)*ab*2;
    ans=min(ans,cnt);
    cnt=0;
    //a,bだけで買う
    cnt=xa*a+xb*b;
    ans =min(ans,cnt);
    cout<<ans<<endl;
}