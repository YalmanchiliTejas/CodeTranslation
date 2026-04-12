import sys
from itertools import accumulate

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n = int(input())
    A = list(map(int, input().split()))
    R = list(accumulate(A))
    res = 0
    for i in range(n):
        res += (A[i] * (R[-1] - R[i])) % mod
        res %= mod
    print(res)


if __name__ == '__main__':
    resolve()
