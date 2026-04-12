from itertools import product
from collections import defaultdict
def resolve():
    s = input()
    K = int(input())
    dp = defaultdict(int)
    dp[0, 0, 0] = 1
    for i, less, k in product(range(len(s)), (0, 1), range(K+1)):
        max_d = 9 if less else int(s[i])
        max_d = 0 if k == K else max_d
        for d in range(max_d+1):
            less_ = less or d < max_d
            k_ = k + 1 if d > 0 else k
            dp[i + 1, less_, k_] += dp[i, less, k]
    print(sum(dp[len(s), less, K] for less in (0, 1)))
resolve()