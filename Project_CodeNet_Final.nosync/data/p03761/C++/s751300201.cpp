#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main() {
  ll n;
  cin >>n;
  vector<string> vec(n);
  rep(i,n) {
cin >>vec.at(i);
    sort(all(vec.at(i)));
  }
 
  ll data[n][26];
  rep(i,n) {
    rep(j,26) {
      data[i][j]=0;
    }
  }
  
  
  
  
  
  
  
         rep(i,n) {
           rep(j,vec.at(i).size()) {
             data[i][(vec.at(i).at(j)-'a')]++;
             
           }
         }

       vl a1(n);
  vl a2(n);
  vl a3(n);
  vl a4(n);
  vl a5(n);
  vl a6(n);
  vl a7(n);
  vl a8(n);
  vl a9(n);
  vl a10(n);
  vl a11(n);
  vl a12(n);
  vl a13(n);
  vl a14(n);
  vl a15(n);
  vl a16(n);
  vl a17(n);
  vl a18(n);
  vl a19(n);
  vl a20(n);
  vl a21(n);
  vl a22(n);
  vl a23(n);
  vl a24(n);
  vl a25(n);
  vl a26(n);
  rep(i,n) {
    a1.at(i)=data[i][0];
  }
  
  rep(i,n) {
    a2.at(i)=data[i][1];
  }
  
  rep(i,n) {
    a3.at(i)=data[i][2];
  }
  
  rep(i,n) {
    a4.at(i)=data[i][3];
  }
  
  rep(i,n) {
    a5.at(i)=data[i][4];
  }
  
  rep(i,n) {
    a6.at(i)=data[i][5];
  }
  
  rep(i,n) {
    a7.at(i)=data[i][6];
  }
  
  rep(i,n) {
    a8.at(i)=data[i][7];
  }
  
  rep(i,n) {
    a9.at(i)=data[i][8];
  }
  
  rep(i,n) {
    a10.at(i)=data[i][9];
  }
  
  rep(i,n) {
    a11.at(i)=data[i][10];
  }
  
  rep(i,n) {
    a12.at(i)=data[i][11];
  }
  
  rep(i,n) {
    a13.at(i)=data[i][12];
  }
  
  rep(i,n) {
    a14.at(i)=data[i][13];
  }
  
  rep(i,n) {
    a15.at(i)=data[i][14];
  }
  
  rep(i,n) {
    a16.at(i)=data[i][15];
  }
  
  rep(i,n) {
    a17.at(i)=data[i][16];
  }
  
  rep(i,n) {
    a18.at(i)=data[i][17];
  }
  
  rep(i,n) {
    a19.at(i)=data[i][18];
  }
  
  rep(i,n) {
    a20.at(i)=data[i][19];
  }
  
  rep(i,n) {
    a21.at(i)=data[i][20];
  }
  
  rep(i,n) {
    a22.at(i)=data[i][21];
  }
  
  rep(i,n) {
    a23.at(i)=data[i][22];
  }
  
  rep(i,n) {
    a24.at(i)=data[i][23];
  }
  
  rep(i,n) {
    a25.at(i)=data[i][24];
  }
  
  rep(i,n) {
    a26.at(i)=data[i][25];
  }
  
  sort(all(a1));
  sort(all(a2));
  sort(all(a3));
  sort(all(a4));
  sort(all(a5));
  sort(all(a6));
  sort(all(a7));
  sort(all(a8));
  sort(all(a9));
  sort(all(a10));
  sort(all(a11));
  sort(all(a12));
    sort(all(a13));    
   sort(all(a14));      
   sort(all(a15)); 
   sort(all(a16));          
  sort(all(a17));
  sort(all(a18));
  sort(all(a19));
  sort(all(a20));
  sort(all(a21));
  sort(all(a22));
  sort(all(a23));
  sort(all(a24));
  sort(all(a25));
  sort(all(a26));
  
  string SS;
  rep(i,a1.at(0)) {
    SS+='a';
  }
  
  rep(i,a2.at(0)) {
    SS+='b';
  }
  rep(i,a3.at(0)) {
    SS+='c';
  }
  rep(i,a4.at(0)) {
    SS+='d';
  }
  rep(i,a5.at(0)) {
    SS+='e';
  }
  rep(i,a6.at(0)) {
    SS+='f';
  }
  rep(i,a7.at(0)) {
    SS+='g';
  }
  rep(i,a8.at(0)) {
    SS+='h';
  }
  rep(i,a9.at(0)) {
    SS+='i';
  }
  rep(i,a10.at(0)) {
    SS+='j';
  }
  rep(i,a11.at(0)) {
    SS+='k';
  }
  rep(i,a12.at(0)) {
    SS+='l';
  }
  rep(i,a13.at(0)) {
    SS+='m';
  }
  rep(i,a14.at(0)) {
    SS+='n';
  }
  rep(i,a15.at(0)) {
    SS+='o';
  }
  rep(i,a16.at(0)) {
    SS+='p';
  }
  rep(i,a17.at(0)) {
    SS+='q';
  }
  rep(i,a18.at(0)) {
    SS+='r';
  }
  rep(i,a19.at(0)) {
    SS+='s';
  }
  rep(i,a20.at(0)) {
    SS+='t';
  }
  rep(i,a21.at(0)) {
    SS+='u';
  }
  rep(i,a22.at(0)) {
    SS+='v';
  }
  rep(i,a23.at(0)) {
    SS+='w';
  }
  rep(i,a24.at(0)) {
    SS+='x';
  }
  rep(i,a25.at(0)) {
    SS+='y';
  }
  rep(i,a26.at(0)) {
    SS+='z';
  }
  
  
  
  cout<<SS<<endl;
}
  
