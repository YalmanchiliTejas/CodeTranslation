#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<fstream>
#include<algorithm>
#include<utility>
using namespace std;
using ll = long long;

int main(){
  string str;
  cin >> str;
  if(str[0]==str[1]&&str[1]==str[2])  cout << "No";
  else  cout << "Yes";
  return 0;
}