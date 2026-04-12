#include <iostream>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#define rep(i, n) for(int (i) = (0); (i) < (n); (i)++)
//#define int long long
#define asort(v, n) sort((v), (v + n)) //Using array
#define vsort(v) sort((v).begin(), (v).end()) // Using vector
#define vint vector<int>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  if(n == m)cout << "Yes" << endl;
  else cout << "No" << endl;
}
