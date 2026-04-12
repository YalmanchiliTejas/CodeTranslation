#include <bits/stdc++.h>  // ver1.9.4
#define int long long
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define pb push_back
#define mp make_pair
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define Vout(a) rep(i,0,a.size()-1)cout<<a[i]<<' ';cout<<a[a.size()-1]<<endl;
#define INF 9000000000000000000  //  9.0 * 10^18
#define MOD 1000000007  //  10^9 + 7
using namespace std;

signed main() {
  cout << fixed << setprecision(15);
  int h,w;
  cin >> h >> w;
  vector<vector<char>> mapp(h+2,vector<char>(w+2));
  int ct=0;
  char c;
  rep(i,0,h){
    rep(j,0,w){
      cin >> c;
      if(c=='#')ct++;
      mapp[i][j]=c;
    }
  }
  if(ct!=h+w-1) {cout<<"Impossible"<<endl;return 0;}
  int nowh=0,noww=0;
  while(!(nowh==h-1&&noww==w-1)){
    if(mapp[nowh+1][noww]=='#') {nowh++;continue;}
    if(mapp[nowh][noww+1]=='#') {noww++;continue;}
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  return 0;
}
