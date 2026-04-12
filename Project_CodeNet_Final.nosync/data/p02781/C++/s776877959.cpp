#include <iostream>
#include <utility>
#include <stdint.h>
#include <string>
#include <vector>
#include <array>

using namespace std;

int main()
{
  string sN;
  cin >> sN;
  int K;
  cin >> K;

  vector<uint16_t> N;

  for (const char sn : sN) {
    N.push_back(sn-'0');
    cerr << N.back();
  }
  cerr << endl;
  
  vector<array<uint64_t,4>> DPsmall(N.size());
  vector<array<uint64_t,4>> DPsame(N.size());

  DPsmall[0][1] = N[0] - 1;
  DPsmall[0][2] = DPsmall[0][3] = 0;

  DPsame[0][1] = 1;
  DPsame[0][2] = DPsame[0][3] = 0;

  // {
  //   int n=0;
  //   cerr << DPsmall[n][1] << " " << DPsmall[n][2] << " " << DPsmall[n][3] << "    ";
  //   cerr << DPsame[n][1] << " " << DPsame[n][2] << " " << DPsame[n][3] << " ";
  //   cerr << endl;
  // }
  
  for (int n=1; n<N.size(); ++n) {
    DPsmall[n][1] = 9;
    
    DPsmall[n][1] += DPsmall[n-1][1];
    DPsmall[n][2] += DPsmall[n-1][1]*9 + DPsmall[n-1][2];
    DPsmall[n][3] += DPsmall[n-1][2]*9 + DPsmall[n-1][3];

    if (N[n] > 0) {
      DPsmall[n][1] += DPsame[n-1][1];
      DPsmall[n][2] += DPsame[n-1][1]*(N[n]-1) + DPsame[n-1][2];
      DPsmall[n][3] += DPsame[n-1][2]*(N[n]-1) + DPsame[n-1][3];
    }

    if (N[n] == 0) {
      DPsame[n][1] = DPsame[n-1][1];
      DPsame[n][2] = DPsame[n-1][2];
      DPsame[n][3] = DPsame[n-1][3];
    } else {
      DPsame[n][1] = DPsame[n-1][0];
      DPsame[n][2] = DPsame[n-1][1];
      DPsame[n][3] = DPsame[n-1][2];
    }

    // cerr << DPsmall[n][1] << " " << DPsmall[n][2] << " " << DPsmall[n][3] << "    ";
    // cerr << DPsame[n][1] << " " << DPsame[n][2] << " " << DPsame[n][3] << " ";
    // cerr << endl;
  }

  cout << DPsmall[N.size()-1][K] + DPsame[N.size()-1][K] << endl;
  
  return 0;
}
