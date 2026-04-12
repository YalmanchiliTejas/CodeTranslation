#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N; cin.ignore();
  int A;
  vector<vector<int>> colors;
  cin >> A; cin.ignore();
  colors.push_back( vector<int>(1,A) );
  for(int i=1;i<N;i++){
    cin >> A; cin.ignore();
    int minIndex=-1;
    for(int j=colors.size()-1;j>=0;j--){
      if(A <= colors[j].back()) break;
      else{
        minIndex = j;
      }
    }
    if( minIndex == -1 ) colors.push_back( vector<int>(1,A) );
    else colors[minIndex].push_back( A );
  }
  cout << colors.size() << endl;
}