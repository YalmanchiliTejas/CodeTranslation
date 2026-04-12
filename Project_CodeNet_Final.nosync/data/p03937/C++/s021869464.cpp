#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  int h,w;
  cin>>h>>w;
  vector<string> a(h+1);
  REP(i,h) cin>>a[i];

  int cnt=0;
  REP(i,h){
    REP(j,w){
      if(a[i][j]=='#') cnt++;
    }
  }
  cout<<((cnt==h+w-1)? "Possible":"Impossible")<<endl;

  return 0;
}