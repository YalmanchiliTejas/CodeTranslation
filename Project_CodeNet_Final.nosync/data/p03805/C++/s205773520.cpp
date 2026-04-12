#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> ff(N, vector<bool> (N, false));
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b; a--; b--;
    ff.at(a).at(b) = true;
    ff.at(b).at(a) = true;
  }
  vector<int> num(N);
  for(int i = 0; i < N ; i++) {
    num.at(i) = i;
  }
  int count = 0;
  do {
    bool judge = true;
    /*for(int i = 0; i < num.size(); i++) {
      cout << num.at(i) << " ";
    }*/
    for(int i = 0; i < num.size() - 1; i++) {
      //cout << i;
      if(num.at(0) != 0) {
        judge = false;
        break;
      } else if(ff.at(num.at(i)).at(num.at(i + 1)) == false) {
        judge = false;
        break;
      }
    }
    //cout << endl;
    if(judge) {
      count++;
    }
  } while (next_permutation(num.begin(), num.end()));
  cout << count << endl;
}