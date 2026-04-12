import numpy as np


def main():
    n = [int(x) for x in input()]
    K = int(input())
    dp = np.zeros((len(n)+1, 2, 5), dtype=int)

    if len(n) < K:
        print(0)
        return

    dp[0, 0, 0] = 1

    for i in range(len(n)):
        for k in range(K+1):
            # use 0
            if n[i] == 0:
                dp[i+1, 0, k] += dp[i, 0, k]
                dp[i+1, 1, k] += dp[i, 1, k]
            else:
                dp[i+1, 1, k] += dp[i, 0, k] + dp[i, 1, k]
            # use 1~9
            for x in range(1, 10):
                if x < n[i]:
                    # always smaller
                    dp[i+1, 1, k+1] += dp[i, 0, k] + dp[i, 1, k]
                elif x == n[i]:
                    dp[i+1, 0, k+1] += dp[i, 0, k]
                    dp[i+1, 1, k+1] += dp[i, 1, k]
                else:
                    dp[i+1, 1, k+1] += dp[i, 1, k]
    print(dp[len(n), 0, K] + dp[len(n), 1, K])


if __name__ == '__main__':
    main()