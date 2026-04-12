import sys
input = sys.stdin.readline
from itertools import accumulate


def read():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    return N, A


def solve(N, A, MOD=10**9+7):
    S = list(accumulate(A[::-1]))[::-1]
    ans = 0
    for i in range(N-1):
        ans += A[i] * S[i+1]
        ans %= MOD
    return ans


if __name__ == '__main__':
    inputs = read()
    outputs = solve(*inputs)
    if outputs is not None:
        print("%s" % str(outputs))
