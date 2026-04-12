#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

bool right(char c){
  return c=='y'||c=='u'||c=='i'||c=='o'||c=='p'||c=='h'||c=='j'||c=='k'||c=='l'||c=='n'||c=='m';
}

int main(){ _;
  string s;
  while(cin>>s,s!="#"){
    bool r=right(s[0]);
    int count=0;
    REP(i,s.size()){
      bool tmp=right(s[i]);
      if(r!=tmp) count++;
      r=tmp;
    }
    cout<<count<<endl;
  }
}