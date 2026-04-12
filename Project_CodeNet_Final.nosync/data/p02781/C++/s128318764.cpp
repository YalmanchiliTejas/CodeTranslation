#include <bits/stdc++.h>

using namespace std;

int64_t dp_same[110][12][110];
int64_t dp_small[110][12][110];

int main() {
  string N;
  int K;
  cin >> N >> K;
  int L = N.length();

  memset(dp_same, 0LL, sizeof(dp_same));
  memset(dp_small, 0LL, sizeof(dp_small));
  dp_same[0][0][0] = 1;

  for (int n = 0; n < L; n++) {
    int d = N[n] - '0';

    for (int d_prev = 0; d_prev < 10; d_prev++) {
      for (int k_prev = 0; k_prev <= n; k_prev++) {
	// same -> same (choose d)
	{
	  int choice = d;
	  int plus_non_zero = (choice == 0) ? 0 : 1;
	  dp_same[n + 1][choice][k_prev + plus_non_zero] += dp_same[n][d_prev][k_prev];
	}

	// same -> small (choose 0..d-1)
	{
	  for (int choice = 0; choice < d; choice++) {
	    int plus_non_zero = (choice == 0) ? 0 : 1;
	    dp_small[n + 1][choice][k_prev + plus_non_zero] += dp_same[n][d_prev][k_prev];
	  }
	}

	// small -> small (choose 0..d)
	{
	  for (int choice = 0; choice <= 9; choice++) {
	    int plus_non_zero = (choice == 0) ? 0 : 1;
	    dp_small[n + 1][choice][k_prev + plus_non_zero] += dp_small[n][d_prev][k_prev];
	  }
	}
      }
    }
  }

  int64_t result = 0;
  for (int i = 0; i < 10; i++) {
    result += dp_same[L][i][K];
    result += dp_small[L][i][K];
  }
  cout << result << endl;
  return 0;
}
