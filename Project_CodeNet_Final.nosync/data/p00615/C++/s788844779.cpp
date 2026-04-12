#include<iostream>
#include<algorithm>
using namespace std;
#define FOR(i,b,n) for(int i = (b) ; i < (n) ; ++i)
#define rep(i,n) FOR(i,0,n)
int main(){
  int a,b,data[20000];
  while(cin >> a >> b , a || b){
    rep(i,a+b) cin >> data[i];
    sort(data,data+a+b);
    int ans = data[0];
    FOR(i,1,a+b) ans = max(ans,data[i]-data[i-1]);
    cout << ans << endl;
  }
}