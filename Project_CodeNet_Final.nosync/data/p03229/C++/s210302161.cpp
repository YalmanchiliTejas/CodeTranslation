#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  vector<long long> v1, v2;
  long long n, sum1 = 0, sum2 = 0;
  cin >> n;
  
  for (long long i = 0; i < n; i++)
  {
    long long a;
    cin >> a;
    v1.push_back(a);
    v2.push_back(a);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  long long min = v1[0];
  v1.erase(v1.begin());
  if (v1.size() == 1)
  {
    sum1 += abs(v1[v1.size() - 1] - min);
    // cout << v1[v1.size()-1] << min<< sum1 << endl;
  }
  else
  {
    sum1 += abs(v1[v1.size()-1] - min) + abs(v1[v1.size() - 2] - min);
    // cout << v1[v1.size()-1] << v1[0] << v1[v1.size() - 2] << v1[1]<< sum1 << endl;
  }
  while (true){
    if (v1.size() >= 4){
     long long add = abs(v1[v1.size()-1] - v1[0]) + abs(v1[v1.size() - 2] - v1[1]) > abs(v1[v1.size()-1] - v1[1]) + abs(v1[v1.size() - 2] - v1[0]) ? abs(v1[v1.size()-1] - v1[0]) + abs(v1[v1.size() - 2] - v1[1]) : abs(v1[v1.size() -1] - v1[1]) + abs(v1[v1.size() - 2] - v1[0]);
     sum1 += add;
     //cout << v1[v1.size()-1] << v1[0] << v1[v1.size() - 2] << v1[1]<< sum1 << endl;
      v1.pop_back();
      v1.pop_back();
      
    }
    else if (v1.size() == 3){
      long long add = abs(v1[v1.size()-1] - v1[0]);
      sum1 += add;
      break;
    }
    else{
      break;
    }
    if (v1.size() >= 4){
      long long add = abs(v1[v1.size()-1] - v1[0]) + abs(v1[v1.size() - 2] - v1[1]) > abs(v1[v1.size()-1] - v1[1]) + abs(v1[v1.size() - 2] - v1[0]) ? abs(v1[v1.size()-1] - v1[0]) + abs(v1[v1.size() - 2] - v1[1]) : abs(v1[v1.size() -1] - v1[1]) + abs(v1[v1.size() - 2] - v1[0]);
      sum1 += add;
      v1.erase(v1.begin());
      v1.erase(v1.begin());
    }
    else if (v1.size() == 3){
      long long add = abs(v1[v1.size()-1] - v1[0]);
      sum1 += add;
      break;
    }
    else{
      break;
    }
    //cout << v1[v1.size()-1] << v1[0] << v1[v1.size() - 2] << v1[1]<< sum1 << endl;

  }

  ///v2///
  long long max = v2[v2.size()-1];
  v2.pop_back();
  if (v2.size() == 1)
  {
    sum2 += abs(v2[0] - max);
  }
  else
  {
    sum2 += abs(v2[0] - max) + abs(v2[1] - max);
  }
  while (true){
    if (v2.size() >= 4){
      long long add = abs(v2[v2.size()-1] - v2[0]) + abs(v2[v2.size() - 2] - v2[1]) > abs(v2[v2.size()-1] - v2[1]) + abs(v2[v2.size() - 2] - v2[0]) ? abs(v2[v2.size()-1] - v2[0]) + abs(v2[v2.size() - 2] - v2[1]) : abs(v2[v2.size() -1] - v2[1]) + abs(v2[v2.size() - 2] - v2[0]);
      sum2 += add;
      v2.erase(v2.begin());
      v2.erase(v2.begin());
    }
    else if (v2.size() == 3){
      long long add = abs(v2[v2.size()-1] - v2[0]);
      sum2 += add;
      break;
    }
    else{
      break;
    }
    if (v2.size() >= 4){
     long long add = abs(v2[v2.size()-1] - v2[0]) + abs(v2[v2.size() - 2] - v2[1]) > abs(v2[v2.size()-1] - v2[1]) + abs(v2[v2.size() - 2] - v2[0]) ? abs(v2[v2.size()-1] - v2[0]) + abs(v2[v2.size() - 2] - v2[1]) : abs(v2[v2.size() -1] - v2[1]) + abs(v2[v2.size() - 2] - v2[0]);
     sum2 += add;
      v2.pop_back();
      v2.pop_back();
      
    }
    else if (v2.size() == 3){
      long long add = abs(v2[v2.size()-1] - v2[0]);
      sum2 += add;
      break;
    }
    else{
      break;
    }
  }

  long long sum = sum1 > sum2 ? sum1 : sum2;
  cout << sum << endl;
  return 0;
}
