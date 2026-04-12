#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<b;i++)
int main(){
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,0,h){
            cin>>s[i];
    }
    vector<int> cnt1(h),cnt2(w);
    rep(i,0,h){
        rep(j,0,w) {
            if (s[i][j]=='#') {
                cnt1[i]++;//i行目は消えない
                cnt2[j]++;//j列目は消えない
            }
        }
    }
    rep(i,0,h){
        if(cnt1[i]!=0){
            rep(j,0,w){
                if(cnt2[j]!=0) cout<<s[i][j];
            }
        }
    cout<<endl;//1行出力→改行
    }
}
