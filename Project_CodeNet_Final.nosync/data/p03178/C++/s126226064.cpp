#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG10K (100000L)
#define MAX_D (100L)
#define NUM_MOD (1000000007L)
#define SIZE_BUF (30L)

long mod(long n, long k) {
  const long num = n % k;
  if (num >= 0) {
    return num;
  } else {
    return num + k;
  }
}

long dpss[MAX_LOG10K][MAX_D];

int main() {
  // read inputs
  long ks[MAX_LOG10K], num_digits = 0, D;
  char buf[SIZE_BUF], c;
  while ((c = fgetc(stdin)) != '\n') {
    ks[num_digits++] = c - '0';
  }
  scanf("%ld", &D);
  //   for (long i = 0; i < num_digits; i++) {
  //     printf("i = %ld, ks[i] = %ld\n", i, ks[i]);
  //   }

  // solve dp
  // dpss[i][j] : The number of i digit numbers where the mod D of the sum of
  //              the digits is equal to j
  // initialize
  for (long j = 0; j < D; j++) {
    dpss[0][j] = j == 0;
  }
  // update
  for (long i = 1; i <= num_digits; i++) {
    for (long j = 0; j < D; j++) {
      long dp = 0;
      for (long d = 0; d < 10; d++) {
        dp = mod(dp + dpss[i - 1][mod(j - d, D)], NUM_MOD);
      }
      dpss[i][j] = dp;
      //   printf("%ld ", dp);
    }
    // printf("\n");
  }
  // calculate answer
  long ans = 0, sum_digits = 0;
  for (long i = 0; i < num_digits; i++) {
    const long k = ks[i];
    for (long d = 0; d < k; d++) {
      const long s = (sum_digits + d) % D,
                 num = dpss[num_digits - 1 - i][mod(-s, D)];
      ans = mod(ans + num, NUM_MOD);
      //   printf("i = %ld, d = %ld, s = %ld, num = %ld\n", i, d, s, num);
    }
    sum_digits = (sum_digits + k) % D;
  }
  if (sum_digits % D == 0) {
    ans = mod(ans + 1, NUM_MOD);  // add K if its digit sum is divisible by D
  }
  ans = mod(ans - 1, NUM_MOD);  // remove 0
  printf("%ld\n", ans);
}