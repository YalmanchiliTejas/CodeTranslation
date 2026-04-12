#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <deque>
#include <stdint.h>
#include <utility>

using namespace std;

uint64_t calc(vector<int>& B)
{
  uint64_t ans = 0;
  for (int ii=0; ii<B.size()-1; ++ii) {
    ans += abs(B[ii+1]-B[ii]);
  }
  return ans;
}

void arrange_odd(deque<int>& A, vector<int>& B)
{
  int N = A.size();
  int idx_center = N/2;
  B[idx_center] = A.front();
  A.pop_front();
  int NN = (N-1)/2;

  for (auto b : B)
    cerr << b;
  cerr << endl;
  
  for (int n=0; n<2*(NN/2); ++n) {
    if (n%2==1)
      B[idx_center-2*(n/2)-2] = A.front();
    else
      B[idx_center+2*(n/2)+2] = A.front();
    A.pop_front();
  }

  for (int n=0; n<2*((NN+1)/2); ++n) {
    if (n%2==1)
      B[idx_center-2*(n/2)-1] = A.back();
    else
      B[idx_center+2*(n/2)+1] = A.back();
    A.pop_back();
  }

  for (auto b : B)
    cerr << b;
  cerr << endl;

}

void arrange_even(deque<int>& A, vector<int>& B)
{
  int N = A.size();
  int idx_center1 = N/2;
  int idx_center2 = N/2-1;
  B[idx_center1] = A.front();
  A.pop_front();
  B[idx_center2] = A.back();
  A.pop_back();
  int NN = (N-2)/2;

  for (auto b : B)
    cerr << b;
  cerr << endl;

  for (int n=0; n<NN; ++n) {
    cerr << n << endl;
    if (n%2==1)
      B[idx_center1+2*(n/2)+2] = A.front();
    else
      B[idx_center1-2*(n/2)-2] = A.front();
    A.pop_front();
  }

  for (auto b : B)
    cerr << b;
  cerr << endl;

  for (int n=0; n<NN; ++n) {
    if (n%2==1)
      B[idx_center2-2*(n/2)-2] = A.back();
    else
      B[idx_center2+2*(n/2)+2] = A.back();
    A.pop_back();
  }

  for (auto b : B)
    cerr << b;
  cerr << endl;
}

int main()
{
  int64_t N;
  cin >> N;

  multiset<int> ms;

  for (int n=0; n<N; ++n) {
    int a;
    cin >> a;
    ms.insert(a);
  }

  if (N%2==1) { // N is odd
    deque<int> A1(N), A2(N);
    copy(ms.begin(), ms.end(), A1.begin());
    copy(ms.rbegin(), ms.rend(), A2.begin());  
    vector<int> B1(N), B2(N);

    arrange_odd(A1,B1);
    arrange_odd(A2,B2);

    cerr << calc(B1) << endl;
    cerr << calc(B2) << endl;
    
    cout << max(calc(B1),calc(B2)) << endl;
    
  } else { // N is even
    deque<int> A1(N), A2(N);
    
    copy(ms.begin(), ms.end(), A1.begin());
    copy(ms.rbegin(), ms.rend(), A2.begin());

    for (auto a : A1)
      cerr << a;
    cerr << endl;
    
    vector<int> B1(N), B2(N);

    arrange_even(A1,B1);
    arrange_even(A2,B2);

    cerr << calc(B1) << endl;
    cerr << calc(B2) << endl;
    
    cout << max(calc(B1),calc(B2)) << endl;
  }

  
  return 0;
}