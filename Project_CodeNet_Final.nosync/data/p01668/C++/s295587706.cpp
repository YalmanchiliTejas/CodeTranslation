#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;
string A,B,C;
ll tk[10003];
ll pk[10003];
ll pk2[10003];
ll sk[10003];

int solve(string &X){
  if( X.size()-1 < C.size() ) return 0;
  
  pk[0] = X[0]-'0';
  for(int i=1;i<(int)X.size();i++){
    ll x = X[i] - '0';    
    pk[i] = ( pk[i-1] * 10LL + x ) % MOD;
  }
  sk[0] = X[X.size()-1] - '0';
  for(int i=1;i<(int)X.size();i++){
    ll x = X[X.size()-1-i]-'0';
    sk[i] = ( sk[i-1] + x * tk[i] ) % MOD;
  }

  ll res = 0;
  if( C == "0" ){
    res = 1;
    for(int i=2;i<=(int)X.size()-(int)C.size();i++){
      string a = X.substr(i,1);
      //    cout << "comp " << a << " " << C << endl;
      if( a > C ){
	res += ( pk[i-1] * tk[X.size()-i-C.size()] ) % MOD;
      } else {
	res += ( (pk[i-1]+MOD-1)%MOD * tk[X.size()-i-C.size()] + ( ((int)X.size()-i-(int)C.size()-1<0)?0:sk[X.size()-i-C.size()-1] ) + 1 ) % MOD;

	//cout << pk[i-1]-1 << " " << tk[X.size()-i-C.size()] << " "<< " " << (((int)X.size()-i-(int)C.size()-1<0)?1:sk[X.size()-i-C.size()-1])  << endl;     
      }
      res %= MOD;
    }
  } else {
    for(int i=1;i<=(int)X.size()-C.size();i++){
      string a = X.substr(i,C.size());
      if( a < C ){
	res += ( pk[i-1] * tk[X.size()-i-C.size()] ) % MOD;
      } else if( a > C ){
	res += ((pk[i-1]+1) * tk[X.size()-i-C.size()]) % MOD;
      } else {

	res += ( (pk[i-1] * tk[X.size()-i-C.size()])%MOD + ( ((int)X.size()-i-(int)C.size()-1<0)?0LL:sk[X.size()-i-C.size()-1] ) + 1LL ) % MOD;
      }
      res %= MOD;    
    }
  }
  //  cout << X<< endl;
  //cout << res << endl;
  return res;
}

int main(){
  cin >> B >> A >> C;
  tk[0] = 1LL;
  for(int i=1;i<=10000;i++){
    tk[i] = (tk[i-1] * 10LL) % MOD;
  }

  A = "0" + A;
  B = "0" + B;

  B[B.size()-1]--;
  for(int i=(int)B.size()-1;i>0;i--){
    if( B[i] < '0' ){
      B[i] = '9';
      B[i-1]--;
    }
    else break;
  }

  if( B[0] < '0' )
    cout << solve( A ) << endl;
  else {
    ll b = solve( B );
    ll a = solve( A );
    //cout << a << " "  << b << endl;
    cout << (a + MOD - b)%MOD << endl;
  }
}