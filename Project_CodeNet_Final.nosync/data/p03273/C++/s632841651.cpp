#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int dp[100009];
vector<int>v;

int main(){
    int h,w;
    cin>>h>>w;
    vector<string>s,ans;
    vector<int>v;
    rep(i,0,h){
        string ss;
        cin>>ss;
        bool c=false;
        rep(j,0,w){
            if(ss.at(j)=='#')c=true;
        }
        if(c)s.push_back(ss);
    }

    rep(i,0,w){
        bool c=false;
        rep(j,0,s.size()){
            if(s.at(j).at(i)=='#')c=true;
        }
        if(c)v.push_back(i);
    }
    /*for(auto p:v){
        cout<<p<<endl;
    }*/

    ans.resize(s.size());
    rep(i,0,s.size()){
        string sa="";
        for(auto j:v){
            sa.push_back(s.at(i).at(j));
        }
        ans.at(i)=sa;
    }

    rep(i,0,s.size()){
        cout<<ans.at(i)<<endl;
    }
return 0;
}