#include <bits/stdc++.h>
using namespace std;
using state= pair<int, int>;

int64_t dp(state stat, const vector<int64_t> &data, map<state, int64_t> *memo){
  if(memo->count(stat)){ return memo->at(stat); }
  else{
    const int N= data.size();
    int rem,id;
    tie(rem, id)= stat;

    if(rem==0){ return memo->operator[](stat)= 0; }
    else if(2*rem- 1 > N-id){
      return memo->operator[](stat)= INT64_MIN;
    }
    else{
      state   pick= make_pair(rem-1, id+2);
      state nopick= make_pair(rem  , id+1);
      return memo->operator[](stat)= max(data.at(id)+ dp(pick, data, memo), dp(nopick, data, memo));
    }
  }
}

int main(){
  int N;
  cin >> N;

  vector<int64_t> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }
  map<state, int64_t> memo;

  cout << dp(make_pair(N/2, 0), data, &memo) << endl;
}