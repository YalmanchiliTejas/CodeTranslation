/*
#include <bits/stdc++.h>
using namespace std;

int main(){

  int a[101] = {};

  for(int i = 0; i < 12; i++){
    int e;
    cin >> e;

    a[e]++;
  }

  int count = 0;

  for(int i = 1; i < 101; i++){
    if(a[i] == 4)count++;
  }

  cout << (count==3 ? "yes" : "no") << endl;

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

  vector<int> V;
  vector<int>::iterator p = V.begin();

  for(int i = 0; i < 12; i++){
    int e;
    cin >> e;
    V.push_back(e);
  }

  sort(V.begin(),V.end());

  //cout << V[1] << " " << V[4] << endl;
  //cout << *p+1 << endl;//error why
  cout << ((V[0]==V[3]&&V[4]==V[7]&&V[8]==V[11])?"yes":"no") << endl;
  return 0;
}

