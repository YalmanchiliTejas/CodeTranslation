#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int i, n, s, sum, avg;
  vector<int> data;

  while(1){
    cin >> n;
    if(n == 0) break;

    for(i=0; i<n; ++i){
      cin >> s;
      data.push_back(s);
    }

    sort(data.begin(), data.end());

    for(i=1, sum=0; i<n-1; ++i)
      sum += data[i];

    avg = sum / (data.size()-2);

    cout << avg << endl;
    data.clear();
  }

  return 0;
}