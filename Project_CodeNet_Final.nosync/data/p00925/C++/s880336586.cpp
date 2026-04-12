#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) (int)((a).size())
typedef long long ll;
typedef pair<int,int> PI;

int main(int argc, char *argv[])
{
  string ex;
  cin >> ex;
  int m;
  cin >> m;
  int n = ex.size();

  ll nor = 0;
  ll gre = ex[0] - '0';

  for(int i = 1; i <n;++i){
    char op = ex[i];
    ++i;
    if(op=='*') gre *= ex[i]-'0';
    else gre += ex[i] - '0';
  }

  for(int i = 0; i < n; ++i){
    ll nu = ex[i] - '0';
    while(i+1 < n && ex[i+1] == '*'){
      i+=2;
      nu *= ex[i] - '0';
    }
    nor += nu;
    ++i;
  }

  if(nor == gre && nor==m) cout << 'U' << endl;
  if(nor ==m && gre != m) cout << 'M' << endl;
  if(nor !=m && gre == m) cout << 'L' << endl;
  if(nor !=m && gre != m) cout << 'I' << endl;  
  //cout << nor << " " << gre << endl;
  
  
  return 0;
}