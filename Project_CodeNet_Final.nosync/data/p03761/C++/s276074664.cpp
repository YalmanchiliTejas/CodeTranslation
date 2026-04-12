#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
  int N;
  cin >> N;

  vector<string>word(N);
  for(int i=0;i<N;i++){
    cin >> word[i];
  }

  vector<vector<int> >check(N,vector<int>(26,0));
  for(int i=0;i<N;i++){
    int n = word[i].length();
    for(int j=0;j<n;j++){
      check[i][word[i][j] - 'a']++;
    }
  }

  vector<int>usable(26,0);

  for(int i=0;i<26;i++){
    int min_al = 51;
    for(int j=0;j<N;j++){
      if(check[j][i] < min_al)
        min_al = check[j][i];
    }
    usable[i] = min_al;
  }

  for(int i=0;i<26;i++){
    if(usable[i] == 0)
      continue;
    else{
      for(int j=0;j<usable[i];j++){
        cout << char(i + 'a');
      }
    }
  }

  cout << endl;

  return 0;
}
