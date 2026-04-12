#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> a;
  int temp;
  for(int i = 0;i < 12;++i){
    cin >> temp;
    a.push_back(temp);
  }

  sort(a.begin(), a.end());

  bool flag = true;
  for(int i = 0;i < 4 - 1 && flag;++i){
    if(a[i] != a[i + 1]) flag = false;
  }

  for(int i = 4;i < 8 - 1 && flag;++i){
    if(a[i] != a[i + 1]) flag = false;
  }

  for(int i = 8;i < 12 - 1 && flag;++i){
    if(a[i] != a[i + 1]) flag = false;
  }

  if(flag){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }

  return 0;
}

