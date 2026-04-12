#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define srt(i) sort(i.begin(), i.end())
#define rvt(i) sort(i.begin(), i.end(), greater<int>())
 
int main() {
  int n,m;
  cin >> n >> m;

  vector<string> ab(m);
  rep(i,m){
    string a,b;
    cin >> a>> b;
    ab.at(i) = a + b;
  }

  vector<int> edge(n);
  rep(i,n) edge.at(i) = i+1;
  srt(edge);

  int cnt=0;
  do{
    if(edge.at(0)!=1) continue;

    bool isAll = true;;
    for(int i=0; i<n-1; i++){
      int ai = edge.at(i);
      int bi = edge.at(i+1);

      bool isCon = false;
      for(string tmp: ab){
        if((ai==(tmp.at(0)-'0') && bi==(tmp.at(1)-'0') )||
           (ai==(tmp.at(1)-'0') && bi==(tmp.at(0)-'0') )) {
          isCon = true; 
          break;
        }
      }
      if(!isCon){
        isAll = false;
        break;
      }
    }

    if(isAll) cnt++;

  }while(next_permutation(edge.begin(), edge.end()));

  cout << cnt << endl;
}