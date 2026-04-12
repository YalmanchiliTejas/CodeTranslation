#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

vector<string> encode(string s) {
  rep(i,(int)s.size()) if( s[i] == '/' ) s[i] = ' ';
  stringstream ss;
  ss << s;
  vector<string> field;
  while( ss >> s ) {
    string tmp = "";
    rep(i,(int)s.size()) {
      if( s[i] == 'b' ) {
	tmp += "b";
      } else {
	tmp += string(s[i]-'0',' ');
      }
    }
    field.push_back(tmp);
  }
  return field;
}

string decode(vector<string> vec,int a,int b,int c,int d) {
  --a, --b, --c, --d;
  swap(vec[a][b],vec[c][d]);
  string ret = "";
  rep(i,(int)vec.size()) {
    if( i ) ret += "/";
    int cnt = 0;
    rep(j,(int)vec[i].size()) {
      if( vec[i][j] == 'b' ) {
	if( cnt ) {
	  ret += string(1,(char)('0'+cnt));
	  cnt = 0;
	}
	ret += "b";
      } else {
	++cnt;
      }
    }
    if( cnt ) {
      ret += string(1,(char)('0'+cnt));
      cnt = 0;
    }
  }
  return ret;
}

int main() {
  string s;
  int a,b,c,d;
  while( cin >> s, s[0] != '#' ) {
    cin >> a >> b >> c >> d;
    vector<string> field = encode(s);
    cout << decode(field,a,b,c,d) << endl;
  }
  return 0;
}