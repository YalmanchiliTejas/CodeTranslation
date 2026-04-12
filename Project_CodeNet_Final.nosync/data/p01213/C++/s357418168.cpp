#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int table[310][310];

string backtrace(const string &s,const string &t,int i,int j) {
    if(i == 0 || j == 0) return "";
    else if(s[i-1] == t[j-1]) {
        return backtrace(s,t,i-1,j-1) + s[i-1];
    }else {
        if(table[i][j-1] > table[i-1][j]) return backtrace(s,t,i,j-1);
        else return backtrace(s,t,i-1,j);
    }
}

string lcs(const string &s,const string &t) {
  memset(table, 0, sizeof(table));

  for(int i=0; i<=s.length(); ++i)
    for(int j=0; j<=t.length(); ++j)
      table[i][j] = 0;

  for(int i=1; i<=s.length(); ++i) {
    for(int j=1; j<=t.length(); ++j) {
      int m = (s[i-1] == t[j-1]) ? 1 : 0;
      int value = max(table[i-1][j-1] + m, max(table[i-1][j], table[i][j-1]));
      table[i][j] = value;
    }
  }

  return backtrace(s,t,s.length(),t.length());
}


string lps(string s) {
    string s1,s2,ans;
    int ansl = 0;
    for(int i=1; i<s.length(); ++i) {
        string tmp = lcs(s.substr(0,i),s.substr(i));
        if(ans.length() < tmp.length()) {
            ans = tmp;
        }
    }

    return ans;
}


int main() {
    string input;
    while(cin>>input) {
        if(input == "#END") break;
        cout<<lps(input)<<endl;
    }
}