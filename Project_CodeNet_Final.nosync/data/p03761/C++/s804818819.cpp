#include <bits/stdc++.h>
using namespace std;
#define rep for(int i = 0;i<n;i++)
#define ll long long
 
//const int INF = 1e8;
typedef pair<int,int>P;
int dx[4] = {1,0,-1,0};int dy[4] = {0,1,0,-1};
queue<P> que;

int main(){
  int n;cin >> n;
  string al[26],sum;string s;string tmp = "";
  for(int i = 0;i<50;i++) tmp += "a";
  for(int i = 0;i<26;i++) al[i] = tmp;
  //すべての文字列についてアルファベットを数えて上書き　最後に辞書順出力
  rep{
      cin >> s;
      for(int j = 0;j<26;j++){
          tmp ="";
          for(int k = 0;k<s.size();k++){
              if(s.at(k) - 'a' == j ) tmp += s.at(k);
          }
          if(tmp.size() < al[j].size()) al[j] = tmp;
      }
  }
  for(int i = 0;i<26;i++){
      cout << al[i];
  }
  cout << endl;
} 