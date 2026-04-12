#include<iostream>
#include<algorithm>

using namespace std;

struct DATA{
  char name;
  int number;
};

bool compare(const DATA&, const DATA&);

int main(){
  int i, s1, s2;
  char c[5] = {'A', 'B', 'C', 'D', 'E'};
  DATA data[5];

  while(1){
    for(i=0; i<5; ++i){
      cin >> s1 >> s2;
      if(s1 == 0 && s2 == 0) break;
      data[i].name = c[i];
      data[i].number = s1 + s2;
    }

    if(s1 == 0 && s2 == 0) break;
    sort(data, data+5, compare);
    cout << data[0].name << " " << data[0].number << endl;
  }

  return 0;
}

bool compare(const DATA& x, const DATA& y){
  return x.number > y.number;
}