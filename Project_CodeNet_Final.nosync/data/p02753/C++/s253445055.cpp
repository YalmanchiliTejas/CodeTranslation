#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define double long double
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) begin(x), end(x)
using vint = vector<int>;
using vvint = vector<vint>;
using vchar = vector<int>;
using vvchar = vector<vchar>;
constexpr double pi = 3.1415926535897932384626433832795028L;

int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int sigma(int n){
    int sum=0;
    for (int i=1; i<=(n); i++){
        sum+=i;
    }
    return sum;
}
int sigma_2(int n) {
  if (n == 0) {
    return 0;
  }
  return n + sigma_2(n - 1);
}
int sum_range(int a, int b) {
  if (a == b) {
    return a;
  }
  return sum_range(a, b - 1) + b;
}
int distance(int yo,int xo,int yi,int xi){
    return (yo-yi)*(yo-yi)+(xo-xi)*(xo-xi);
}

int array_sum_from_i(vint &data, int i) {
  if (i == data.size()) {
    return 0;
  }
  int s = array_sum_from_i(data, i + 1);
  return data[i] + s;
}
int array_sum(vint &data) {
  return array_sum_from_i(data, 0);
}
bool has_divisor(int N, int i) {
  if (i == N) {
    return false;
  }
  if (N % i == 0) {
    return true;
  }
  return has_divisor(N, i + 1);
}

bool is_prime(int N) {
  if (N == 1) {
    return false;
  }
  else if (N == 2) {
    return true;
  }
  else {
    return !has_divisor(N, 2);
  }
}
bool is_even(int);
bool is_odd(int);

bool is_even(int n) {
  if (n == 0) {
    return true;
  }
  return is_odd(n - 1);
}

bool is_odd(int n) {
  if (n == 0) {
    return false;
  }
  return is_even(n - 1);
}








signed main() {
    string S;
    cin >> S;
    int N = S.length();
    for(int i=1;i<N;i++){
        if(S[i-1]!=S[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;

}
