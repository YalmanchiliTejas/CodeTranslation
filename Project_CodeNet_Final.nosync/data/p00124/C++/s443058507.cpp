#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct DATA{
  string Team;
  int Score;
};

bool compare(const DATA&, const DATA&);

int main(){
  int i, n, win, draw, lose, count=0;
  string s;
  DATA one;
  vector<DATA> data;

  while(1){
    cin >> n;
    if(n == 0) break;
    else if(count != 0) cout << endl;

    for(i=0; i<n; ++i){
      cin >> s >> win >> lose >> draw;
      one.Team = s;
      one.Score = win * 3 + draw;
      data.push_back(one);
    }

    sort(data.begin(), data.end(), compare);

    for(i=0; i<data.size(); ++i)
      cout << data[i].Team << "," << data[i].Score << endl;

    data.clear();
    ++count;
  }

  return 0;
}

bool compare(const DATA& x, const DATA& y){
  return x.Score > y.Score;
}