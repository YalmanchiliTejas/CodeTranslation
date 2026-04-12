#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  int mod = 1000000007;
  cin >> num;
  long long sum=0;
  vector<int> kazu(num);
  vector<long long > sum_i(num+1,0);
  for(int i = 0;i < num;i++)
  {
    cin >>kazu.at(i);
    sum_i.at(i+1) = sum_i.at(i)+ kazu.at(i);
  }
  for(int i = 0;i < num; i++)
  {
    long long sub_sum = (sum_i.at(num)-sum_i.at(i+1))%mod;
    sum += kazu.at(i)*sub_sum;
    sum %= mod;
  }
  cout << sum;
}
