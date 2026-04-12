import functools
import sys

sys.setrecursionlimit(1000000)

N, = (int(x) for x in input().split())
arr = [int(x) for x in input().split()]

@functools.lru_cache(None)
def dp(i, k):
    if k <= 0:
        return 0
    rem = N - i
    if k > (rem // 2) + (rem % 2):
        return -float('inf')
    return max(arr[i] + dp(i + 2, k - 1), dp(i + 1, k))


sol = dp(0, N // 2)

print(sol)
