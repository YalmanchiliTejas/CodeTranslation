#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i, s, n) for(int i=s; i<n; i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
//	std::cout<<std::fixed<<std::setprecision(10);


int main() {
  string S;
  cin >> S;
  if(S=="AAA" || S=="BBB") {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}
