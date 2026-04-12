#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;
#define ll int64_t
const long MOD = 1e9 + 7;




int main()
{
  // string s, m; //かっている数//最大100
  long n;
  cin >> n ;
  vector<long> a(n);
  vector<long> b(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(a.begin(), a.end());

  vector<long> minv;
  vector<long> maxv;



  for (int i = 0; i < n / 2 + n % 2; ++i) {
    minv.push_back(a[i]);
  }

  for (int i = 0; i < n / 2; ++i) {
    maxv.push_back(a[n - 1 - i]);
  }

  vector<long> minv2;
  vector<long> maxv2;

  for (int i = 0; i < minv.size(); ++i) {
    if (i % 2 == 0) {
      minv2.insert(minv2.begin(), minv[i]); //先頭に追加
    } else {
      minv2.push_back(minv[i]);
    }
  }

  for (int i = 0; i < maxv.size(); ++i) {
    if (i % 2 == 0) {
      maxv2.push_back(maxv[i]);
    } else {
      maxv2.insert(maxv2.begin(), maxv[i]); //先頭に追加
    }
  }

  // for (int i = 0; i < minv2.size(); ++i) {
  //   cerr << minv2[i] << ",";
  // } cerr << endl;

  // for (int i = 0; i < maxv2.size(); ++i) {
  //   cerr << maxv2[i] << ",";
  // } cerr << endl;


  vector<long> ansv;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      ansv.push_back(minv2[i/2]);
    } else {
      ansv.push_back(maxv2[i/2]);
    }
  }



  long ans =0;

  for (int i = 0; i < n; ++i) {
    // cerr << ansv[i] << ",";
    if (i>0){
      ans += abs(ansv[i-1] - ansv[i] );
    }
  }

  long ans2 =0;

  vector<long> minw;
  vector<long> maxw;

  for (int i = 0; i < n / 2 ; ++i) {
    minw.push_back(a[i]);
  }

  for (int i = 0; i < n / 2+ n % 2; ++i) {
    maxw.push_back(a[n - 1 - i]);
  }



  vector<long> minw2;
  vector<long> maxw2;

  for (int i = 0; i < minw.size(); ++i) {
    if (i % 2 == 0) {
      minw2.insert(minw2.begin(), minw[i]); //先頭に追加
    } else {
      minw2.push_back(minw[i]);
    }
  }


  for (int i = 0; i < maxw.size(); ++i) {
    if (i % 2 == 0) {
      maxw2.push_back(maxw[i]);
    } else {
      maxw2.insert(maxw2.begin(), maxw[i]); //先頭に追加
    }
  }



  for (int i = 0; i < minw2.size(); ++i) {
    cerr << minw2[i] << ",";
  } cerr << endl;

  for (int i = 0; i < maxw2.size(); ++i) {
    cerr << maxw2[i] << ",";
  } cerr << endl;



  vector<long> answ;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      answ.push_back(maxw2[i/2]);
    } else {
      answ.push_back(minw2[i/2]);
    }
  }



  for (int i = 0; i < n; ++i) {
    cerr << answ[i] << ",";
    if (i>0){
      ans2 += abs(answ[i-1] - answ[i] );
    }
  }



  cout  << max(ans,ans2);

  return 0;
}

























