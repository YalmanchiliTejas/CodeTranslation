#include <iostream>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <float.h>
#include <limits>
#include <vector> 
#include <string.h>

#define rep(i,a,n) for(ll int (i) = (a);(i) < (n);(i)++)
#define urep(i,a,n) for(ll int (i) = (a);(i) > (n);(i)--)
#define MOD 1000000007
#define ll long long
#define asort(a) sort(a.begin(),a.end());

using namespace::std;

int jo(ll int jxo, ll int jyo){//累乗
	ll int jhogeo = 1;
	rep(jinto,0,jyo) jhogeo=jhogeo*jxo;
	return jhogeo;
}
char tobig(char toxbig){//char大文字化
  return (toxbig-0x20);
}
char tolow(char toxlow){//char小文字化
  return (toxlow+0x20);
}
int ctoi(char cctoi){//char->int
  if('0' <= cctoi && cctoi <= '9') return (cctoi-'0');
  return -1;
}
int gcd(int gcad, int gcbd) {//最大公約数
  if(gcad < gcbd) return gcd(gcbd, gcad);
  int gcrd;
  while ((gcrd=gcad%gcbd)) {
    gcad = gcbd;
    gcbd = gcrd;
  }
  return gcbd;
}
int lcm(int lcam, int lcbm){//最小公倍数
 return (lcam*lcbm)/gcd(lcam,lcbm);
}


int main(){
  int N;
  cin>>N;
  int ans=1;
  vector<int> H(N);
  rep(i,0,N) cin>>H[i];
  int mH=H[0];
  rep(i,1,N){
    if(mH<=H[i]){
      ans++;
      mH=H[i];
    }
  }
  cout<<ans;
    

}
// int *p = new int[N];

//  vector<int> 変数名(要素数);
//  sort(変数名.begin(),変数名.end());//昇順ソート

// vector<vector<int>> 変数名(左の個数, vector<int>(右の個数));

//
