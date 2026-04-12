#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  vector<int> v(12);

  for(int i = 0; i < 12; i++) cin >> v[i];

  sort(v.begin(), v.end());

  int cnt = 0;

  if(v[0] == v[3] && v[4] == v[7] && v[8] == v[11]) cout << "yes" << endl;
  else cout << "no" << endl;

  return 0;

}

