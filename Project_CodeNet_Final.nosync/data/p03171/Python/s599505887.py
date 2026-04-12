import sys
from functools import lru_cache
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')

@lru_cache(maxsize=None)
def f(N, *A):
    dp = [[INF] * (N + 1) for _ in range(N + 1)]
    for i in range(N + 1):
        dp[i][i] = 0
    for l in range(1, N + 1):
        for i in range(N - l + 1):
            j = i + l
            if (N - l) % 2 == 0:
                dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j - 1])
            else:
                dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j - 1])
    print(dp[0][N])

def main():
    N = int(readline())
    A = list(map(int, readline().split()))
    f(N,*A)

if __name__ == '__main__':
    main()
