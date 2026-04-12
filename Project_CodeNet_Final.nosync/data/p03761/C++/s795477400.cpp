#include <bits/stdc++.h>
using namespace std;

vector<int> stov(string s){
  sort(s.begin(),s.end());
  vector<int> abc(26);
  int kireme=0;
  for(int ii=97;ii<123;ii++){
    char x = ii;
    for(int jj=kireme;jj<s.size();jj++){
      if(s[jj]==x) abc.at(ii-97)++;
      else{
        kireme = jj;
        break;
      }
    }
  }
  return abc;
}

string vtos(vector<int> abc){
  string s="";
  for(int j1=0;j1<26;j1++){
    for(int i1=0;i1<abc.at(j1);i1++){
      char x=j1+97;
      s += x;
    }
  }
  return s;
}

int main(){
  int n;
  cin>>n;
  vector<string> SS(n);
  vector<vector<int>> ABC(n);
  vector<int> minabc(26,100);
  for(int i=0;i<n;i++){
    cin>>SS.at(i);
    ABC.at(i) = stov(SS.at(i));
    for(int j=0;j<26;j++){
      minabc.at(j) = min(minabc.at(j),ABC.at(i).at(j));
    }
  }
  string ans = vtos(minabc);
  cout << ans << endl;
}
