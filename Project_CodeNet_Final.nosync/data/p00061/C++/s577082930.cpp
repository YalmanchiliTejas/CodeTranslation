#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
 
using namespace std;

struct DATA{
  int number;
  int answer;
  int rank;
};

bool Compare(const DATA&, const DATA&);

int main(){
  int i, num, ans, ran, check;
  char c;
  DATA newdata;
  vector<DATA> data;

  while(1){
    cin >> num >> c >> ans;
    if(num == 0 && ans == 0) break;

    newdata.number = num;
    newdata.answer = ans;
    data.push_back(newdata);
  }

  sort(data.begin(), data.end(), Compare);

  ran = 0;
  for(i=0; i<data.size(); ++i){
    if(i != 0 && data[i].answer == data[i-1].answer){
      data[i].rank = ran;
    }else{
      ++ran;
      data[i].rank = ran;
    }
  }

  while(cin >> check){
    for(i=0; i<data.size(); ++i){
      if(data[i].number == check) break;
    }
    cout << data[i].rank << endl;
  }
  return 0;
}

bool Compare(const DATA& x, const DATA& y){
  return (x.answer > y.answer);
}