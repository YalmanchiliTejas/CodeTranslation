#include <bits/stdc++.h>
using namespace std;
const long long mod = pow(10, 9) + 7;
const long long MOD = 998244353;
const long long INF = 1LL << 60;
const int inf = pow(10, 9) + 7;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, int B) {return (A + (B - 1)) / B;}
long long divCeil(int A, long long B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, long long B) {return (A + (B - 1)) / B;}

int main()
{
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++) cin >> S.at(i);
  
  string abc = "abcdefghijklmnopqrstuvwxyz";
  vector<vector<int>> abcN(n, vector<int>(abc.size(), 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < S.at(i).size(); j++)
    {
      for (int k = 0; k < abc.size(); k++)
      {
        if (S.at(i).at(j) == abc.at(k))
        {
          abcN.at(i).at(k)++;
          break;
        }
      }
    }
  }
  
  for (int i = 0; i < abc.size(); i++)
  {
    int num = inf;
    for (int j = 0; j < n; j++)
    {
      chmin(num, abcN.at(j).at(i));
    }
    
    for (int j = 0; j < num; j++)
    {
      cout << abc.at(i);
    }
  }
  
  cout << endl;
}