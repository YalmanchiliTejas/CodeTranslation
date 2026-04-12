#include <bits/stdc++.h>
using namespace std;
constexpr char sheep= 'S';
constexpr char wolf = 'W';

struct Animal{
  char kind;
  Animal(char c): kind(c){}

  Animal flip() const{
    if(this->kind==sheep){
      return Animal(wolf);
    }
    else{
      return Animal(sheep);
    }
  }
};

int main(){
  const vector<pair<Animal, Animal>> search= {make_pair(Animal(sheep), Animal(sheep))
                                             ,make_pair(Animal(sheep), Animal(wolf) )
                                             ,make_pair(Animal(wolf) , Animal(sheep))
                                             ,make_pair(Animal(wolf) , Animal(wolf) ) };
  int N;
  string S;
  cin >> N >> S;

  auto guess= [&](string cand, int pivot){
    int opponent= (pivot==0) ? 1
                             : pivot- 1;
    char ret= (cand.at(pivot)==sheep) ? (S.at(pivot)=='o') ? Animal(cand.at(opponent)).kind
                                                           : Animal(cand.at(opponent)).flip().kind
                                      : (S.at(pivot)=='o') ? Animal(cand.at(opponent)).flip().kind
                                                           : Animal(cand.at(opponent)).kind       ;
    return ret;
  };

  string ans= "-1";
  for(auto [a0,a1]:search){
    string cand= string(N, 'X');
    cand.at(0)= a0.kind;
    cand.at(1)= a1.kind;
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