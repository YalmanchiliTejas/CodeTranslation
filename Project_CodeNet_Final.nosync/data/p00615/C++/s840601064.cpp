#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
  int a,b;
  while(cin>>a>>b,a+b){
    vector<int>in(a+b);
    rep(i,a)cin>>in[i];
    loop(i,a,a+b)cin>>in[i];
    sort(all(in));
    int maxx=in[0];
    rep(i,a+b-1)maxx=max(maxx,in[i+1]-in[i]);
    cout<<maxx<<endl;
  }
}