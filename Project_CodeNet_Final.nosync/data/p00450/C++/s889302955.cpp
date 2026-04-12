#include<iostream>
#include<vector>

using namespace std;

struct DATA{
  int x;
  int count;
};

void OddNumber(vector<DATA>&, int);
void EvenNnumber(vector<DATA>&, int);

int main(){
  int i, j, n, x, count;
  vector<DATA> data;

  while(1){
    cin >> n;
    if(n == 0) break;

    for(i=0; i<n; ++i){
      cin >> x;
      if(i%2 == 0) OddNumber(data, x);
      else EvenNnumber(data, x);
    }

    for(i=0, count=0; i<data.size(); ++i){
      if(data[i].x == 0)
	count += data[i].count;
    }

    cout << count << endl;
    data.clear();
  }
  return 0;
}

void OddNumber(vector<DATA>& data, int x){
  DATA _data;
  if(data.size() != 0 && x == data[data.size()-1].x){
    ++data[data.size()-1].count;
  }else{
    _data.x = x;
    _data.count = 1;
    data.push_back(_data);
  }
}

void EvenNnumber(vector<DATA>& data, int x){
  if(x == data[data.size()-1].x){
    ++data[data.size()-1].count;
  }else if(data.size() == 1){
      data[data.size()-1].x = x;
      ++data[data.size()-1].count;
  }else{
    data[data.size()-2].count += (data[data.size()-1].count + 1);
    data.pop_back();
  }
}