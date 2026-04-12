#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr char sheep= 'S';
  constexpr char wolf = 'W';
  const vector<pair<char, char>> search= {make_pair(sheep, sheep)
                                         ,make_pair(sheep, wolf )
                                         ,make_pair(wolf , sheep)
                                         ,make_pair(wolf , wolf ) };
  int N;
  string S;
  cin >> N >> S;

  auto guess= [&](const string &cand, int pivot){
    int opponent= (pivot==0) ? 1
                             : pivot- 1;
    char flip= cand.at(opponent) ^ sheep ^ wolf;
    char ret= (cand.at(pivot)==sheep) ? (S.at(pivot)=='o') ? cand.at(opponent)
                                                           : flip
                                      : (S.at(pivot)=='o') ? flip
                                                           : cand.at(opponent);
    return ret;
  };

  string ans= "-1";
  for(auto [a0,a1]:search){
    string cand= string(N, 'X');
    cand.at(0)= a0;
    cand.at(1)= a1;
    char guess_back= guess(cand, 0);
    for(int pivot=1; pivot+1 < N; pivot++){
      cand.at(pivot+1)= guess(cand, pivot);
    }
    char guess_head= guess(cand, N-1);

    if(guess_back==cand.back() && guess_head==cand.at(0)){
      ans= cand;
      break;
    }
  }

  cout << ans << endl;
}