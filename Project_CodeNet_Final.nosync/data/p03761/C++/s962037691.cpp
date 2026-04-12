#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main ()
{
  int n;
  string a, s;
  vector<string> str;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a;
    str.emplace_back(a);
  }
  for(int i = 'a'; i <= 'z'; ++i){
    int cmin = 1000;
    for(int j = 0; j < n; ++j){
      int sum = 0;
      for(int k = 0; k < str[j].size(); ++k){
        if(str[j][k] == i){
          sum = sum + 1;
        }
      }
      if(sum <= cmin){
        cmin = sum;
      }
    }
    for(int b = 0; b < cmin; ++b){
      s += i;
    }
  }
cout << s << endl;
}