#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define inputInt(a) int a; cin >> a; 
#define inputInt2(a,b) int a; int b; cin >> a >> b; 
#define inputInt3(a,b,c) int a; int b; int c; cin >> a >> b >> c;
#define inputLong(a) long a;cin >> a; 
#define inputIntArray(a,N) int a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputLongArray(a,N) long a[N];for(int i=0;i<N;i++){cin >> a[i];}
#define inputIntArray2(a,b,N) int a[N]; int b[N]; for(int i=0;i<N;i++){cin >> a[i] >> b[i];}
#define output(answer) cout << answer << endl;
#define fN(i,N)    for(int i=0; i<N; i++)
#define fSE(i,s,e) for(int i=s; i<=e; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,N) for(int i=0; i<N; i++)
#define cinv(v,N) vector<int> v(N); for(int i=0; i<N; i++){ cin >> v[i]; }
#define mt make_tuple
const ll MOD2 = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
  //input
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll h, w; cin >> h >> w;
  vector<string> s(h);
  FOR(i,h){ cin >> s[i]; }
  
  //main
  map<ll,ll> mh,mw;
  ll ch=0, cw=0;
  FOR(i,h){ 
    FOR(j,w){ 
      if(s[i][j]=='#'){ 
        mh.insert(mp(i,ch));
        ch ++;
        break;
      } 
    } 
  }
  FOR(j,w){ 
    FOR(i,h){ 
      if(s[i][j]=='#'){ 
        mw.insert(mp(j,cw));
        cw ++;
        break;
      } 
    } 
  }
  
  vector<vector<char>> ans(ch,vector<char>(cw,'.'));
  FOR(i,h){
    FOR(j,w){
      if(s[i][j]=='#'){
        ans[mh[i]][mw[j]] = '#'; 
      }
    }
  }
  
  // output
  FOR(i,ch){
    FOR(j,cw){
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}