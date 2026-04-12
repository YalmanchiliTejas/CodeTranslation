#include<bits/stdc++.h>
using namespace std;
 
#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }
 
int main(){
  ll i, j;
  ll h, w;
  cin >> h >> w;
  char a[h][w];
  for(i = 0; i < h; i++)
    for(j = 0; j < w; j++)
      cin >> a[i][j];
  vector<ll> judgeh(h), judgew(w); 
  ll counth = h, countw = w;
  for(i = 0; i < h; i++)
    for(j = 0; j < w && a[i][j] == '.'; j++)
      if(j == w - 1){
        judgeh[i] = 1;
        counth--;
      }
  
  for(i = 0; i < w; i++)
    for(j = 0; j < h && a[j][i] == '.'; j++)
      if(j == h - 1){
        judgew[i] = 1;
        countw--;
      }
  
  //cout << counth spa countw << endl;
  for(i = 0; i < h; i++)
    if(judgeh[i] == 0){
    for(j = 0; j < w; j++)
      if(judgew[j] == 0)
      cout << a[i][j];
    cout << endl;
    }
  
        
        
 
  return 0;
}