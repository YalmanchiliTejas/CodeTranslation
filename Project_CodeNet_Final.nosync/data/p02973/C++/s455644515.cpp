#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> rights(1,-1);

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;

    if(a<=rights[rights.size()-1]){
      rights.push_back(a);
      continue;
    }

    for (int j = 0; j < (int)rights.size(); j++)
    {
      if(rights[j] < a){
        rights[j] = a;
        break;
      }
    }
  }

  cout << rights.size() << endl;
}