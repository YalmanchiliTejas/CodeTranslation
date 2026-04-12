#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;
vector<char> op[2];

class Parsing{
private:
  string parse;
  int pos;
public:
 
  Parsing(string s){
    parse = s;
    pos = 0;
  }

  void reset(){ pos = 0; }

  ll eval(ll a,ll b,char o){ return (o=='+')?a+b:a*b; }

  int fact(){
    ll p=0;
    while('0' <= parse[pos] && parse[pos] <= '9'){
      p *= 10LL;
      p += (ll)( parse[pos]-'0' );
      pos++;
    }
    return p;
  }
 
 ll term(){
    ll p = fact();
    while( 1 ){
      int index = -1;
      rep(i,op[0].size()) if( op[0][i] == parse[pos] ) { index = i; break; }
      if( index == -1 ) break;
      ++pos;
      ll q = fact();
      p = eval(p,q,op[0][index]);
    }
    return p;
  }
 
 ll expression(){
   ll p = term();
    while( 1 ){
      int index = -1;
      rep(i,op[1].size()) if( op[1][i] == parse[pos] ) { index = i; break; }
      if( index == -1 ) break;

      ++pos;
      ll q = term();
      p = eval(p,q,op[1][index]);

    }
    return p;
  } 
 
};


int main(int argc,char* argv[]){
  string s;
  getline(cin,s);
  ll bob;
  cin >> bob;
  Parsing parser(s);
  op[0].push_back('*');
  op[1].push_back('+');
  ll result1 = parser.expression();
  parser.reset();
  rep(i,2) op[i].clear();
  op[0].push_back('+');
  op[0].push_back('*');
  ll result2 = parser.expression();
  bool flag1 = ( bob == result1 );
  bool flag2 = ( bob == result2 );
  if( flag1 && !flag2 ) puts("M");
  else if( !flag1 && flag2 ) puts("L");
  else if( flag1 && flag2 ) puts("U");
  else puts("I");
  return 0;
}