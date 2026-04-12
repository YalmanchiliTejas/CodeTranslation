#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll n, a;
  in(n);
  string s, t;
  in(s);
  bool h;
  t = "SS";
  rep(i, n - 2){
    if(t[i] == 'S' && s[i + 1] == 'o'){
      if(t[i + 1] == 'S')
        t += "S";
      else
        t += "W";
    }
    if(t[i] == 'S' && s[i + 1] == 'x'){
      if(t[i + 1] == 'S')
        t += "W";
      else
        t += "S";
    }
    if(t[i] == 'W' && s[i + 1] == 'o'){
      if(t[i + 1] == 'S')
        t += "W";
      else
        t += "S";
    }
    if(t[i] == 'W' && s[i + 1] == 'x'){
      if(t[i + 1] == 'S')
        t += "S";
      else
        t += "W";
    }
  }
  h = true;
  if(s[0] == 'o'){
    if(t[n - 1] == 'W')
      h = false;
  }
  else{
    if(t[n - 1] == 'S')
      h = false;
  }
  if(s[n - 1] == 'o'){
    if(t[n - 1] == 'S' && t[n - 2] == 'W')
      h = false;
    if(t[n - 1] == 'W' && t[n - 2] == 'S')
      h = false;
  }
  else{
    if(t[n - 1] == 'S' && t[n - 2] == 'S')
      h = false;
    if(t[n - 1] == 'W' && t[n - 2] == 'W')
      h = false;
  }
  if(h){
    out(t);
    memi;
    return 0;
  }
  t = "SW";
  rep(i, n - 2){
    if(t[i] == 'S' && s[i + 1] == 'o'){
      if(t[i + 1] == 'S')
        t += "S";
      else
        t += "W";
    }
    if(t[i] == 'S' && s[i + 1] == 'x'){
      if(t[i + 1] == 'S')
        t += "W";
      else
        t += "S";
    }
    if(t[i] == 'W' && s[i + 1] == 'o'){
      if(t[i + 1] == 'S')
        t += "W";
      else
        t += "S";
    }
    if(t[i] == 'W' && s[i + 1] == 'x'){
      if(t[i + 1] == 'S')
        t += "S";
      else
        t += "W";
    }
  }
  h = true;
  if(s[0] == 'o'){
    if(t[n - 1] == 'S')
      h = false;
  }
  else{
    if(t[n - 1] == 'W')
      h = false;
  }
  if(s[n - 1] == 'o'){
    if(t[n - 1] == 'S' && t[n - 2] == 'W')
      h = false;
    if(t[n - 1] == 'W' && t[n - 2] == 'S')
      h = false;
  }
  else{
    if(t[n - 1] == 'S' && t[n - 2] == 'S')
      h = false;
    if(t[n - 1] == 'W' && t[n - 2] == 'W')
      h = false;
  }
  if(h){
    out(t);
    memi;
    return 0;
  }
  t = "WS";
  rep(i, n - 2){
    if(t[i] == 'S' && s[i + 1] == 'o'){
      if(t[i + 1] == 'S')
        t += "S";
      else
        t += "W";
    }
    if(t[i] == 'S' && s[i + 1] == 'x'){
      if(t[i + 1] == 'S')
        t += "W";
      else
        t += "S";
    }
    if(t[i] == 'W' && s[i + 1] == 'o'){
      if(t[i + 1] == 'S')
        t += "W";
      else
        t += "S";
    }
    if(t[i] == 'W' && s[i + 1] == 'x'){
      if(t[i + 1] == 'S')
        t += "S";
      else
        t += "W";
    }
  }
  h = true;
  if(s[0] == 'o'){
    if(t[n - 1] == 'S')
      h = false;
  }
  else{
    if(t[n - 1] == 'W')
      h = false;
  }
  if(s[n - 1] == 'o'){
    if(t[n - 1] == 'S' && t[n - 2] == 'S')
      h = false;
    if(t[n - 1] == 'W' && t[n - 2] == 'W')
      h = false;
  }
  else{
    if(t[n - 1] == 'S' && t[n - 2] == 'W')
      h = false;
    if(t[n - 1] == 'W' && t[n - 2] == 'S')
      h = false;
  }
  if(h){
    out(t);
    memi;
    return 0;
  }
  t = "WW";
  rep(i, n - 2){
    if(t[i] == 'S' && s[i + 1] == 'o'){
      if(t[i + 1] == 'S')
        t += "S";
      else
        t += "W";
    }
    if(t[i] == 'S' && s[i + 1] == 'x'){
      if(t[i + 1] == 'S')
        t += "W";
      else
        t += "S";
    }
    if(t[i] == 'W' && s[i + 1] == 'o'){
      if(t[i + 1] == 'S')
        t += "W";
      else
        t += "S";
    }
    if(t[i] == 'W' && s[i + 1] == 'x'){
      if(t[i + 1] == 'S')
        t += "S";
      else
        t += "W";
    }
  }
  h = true;
  if(s[0] == 'o'){
    if(t[n - 1] == 'W')
      h = false;
  }
  else{
    if(t[n - 1] == 'S')
      h = false;
  }
  if(s[n - 1] == 'o'){
    if(t[n - 1] == 'S' && t[n - 2] == 'S')
      h = false;
    if(t[n - 1] == 'W' && t[n - 2] == 'W')
      h = false;
  }
  else{
    if(t[n - 1] == 'S' && t[n - 2] == 'W')
      h = false;
    if(t[n - 1] == 'W' && t[n - 2] == 'S')
      h = false;
  }
  if(h){
    out(t);
    memi;
    return 0;
  }
  out(-1);
  memi;
}