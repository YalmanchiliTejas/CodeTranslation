#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
vector<string> del_col(vector<string> const& input){
    int h=input.size();
    int w=input[0].size();
    vector<string> res;
    rep(i,h){
        bool flag=false;
        rep(j,w){
            if(input[i][j]=='#')flag=true;
        }
        if(flag)res.push_back(input[i]);
    }
    return res;
}
vector<string> del_row(vector<string> const& input){
    int h=input.size();
    int w=input[0].size();
    vector<string> res;
    rep(j,w){
        bool flag=false;
        string buf;
        rep(i,h){
            buf+=input[i][j];
            if(input[i][j]=='#')flag=true;
        }
        if(flag)res.push_back(buf);
    }
    return res;
}
void output(vector<string> const& a){
    int h=a.size();
    int w=a[0].size();
    rep(j,w){
        rep(i,h){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
signed main(){
  int h,w;cin>>h>>w;
  vector<string> a(h);
  rep(i,h)cin>>a[i];
  a=del_col(a);
  a=del_row(a);
  output(a);
  return 0;
}