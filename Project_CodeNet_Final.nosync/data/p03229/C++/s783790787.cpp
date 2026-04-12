#include <bits/stdc++.h>
using namespace std;
const long long mod = pow(10, 9) + 7;
const long long INF = 1LL << 60;
template <class T> bool chmin(T& a, T b){if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b){if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, int B) {return (A + (B - 1)) / B;}
long long divCeil(int A, long long B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, long long B) {return (A + (B - 1)) / B;}

vector<vector<long long>> B;

long long ans0(int T)
{
  long long R = 0;
  for (int i = 1; i < B.at(T).size(); i++)
  {
    if (B.at(T).at(i) != -1 && B.at(T).at(i - 1) != -1)
      R += abs(B.at(T).at(i) - B.at(T).at(i - 1));
  }
  return R;
}

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  sort(A.begin(), A.end());
  
  vector<long long> B0, B1;
  int a, b;
  int n = (N + 1) / 2 * 2;

  for (int i = 0; i < (N - 1) / 2; i++)
  {
    B0.push_back(A.at(i));
    B0.push_back(A.at(N - 1 - i));
    B1.push_back(A.at(N - 1 - i));
    B1.push_back(A.at(i));
  }
  
  if (N % 2 == 0) a = A.at(N / 2 - 1), b = A.at(N / 2);
  else a = A.at(N / 2), b = -1;
  
  B0.insert(B0.begin(), a);
  B0.push_back(b);
  B.push_back(B0);
  
  swap(B0.at(0), B0.at(n - 1));
  B.push_back(B0);
  
  B1.insert(B1.begin(), a);
  B1.push_back(b);
  B.push_back(B1);
  
  swap(B1.at(0), B1.at(n - 1));
  B.push_back(B1);
  
  /*
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < B.at(i).size(); j++)
    {
      cout << B.at(i).at(j) << " ";
    }
    cout << endl;
  }
  */
  
  long long ans = max({ans0(0), ans0(1), ans0(2), ans0(3)});
  
  cout << ans << endl;
}