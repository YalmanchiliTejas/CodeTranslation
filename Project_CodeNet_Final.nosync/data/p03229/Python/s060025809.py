import sys
from collections import deque

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n = int(input())
    A = sorted(list(int(input()) for _ in range(n)))
    B = deque([])
    for i in range(n // 2):
        if i % 2 == 0:
            B.appendleft(A[i])
            B.append(A[-(i + 1)])
        else:
            B.append(A[i])
            B.appendleft(A[-(i + 1)])

    if n % 2 != 0:
        if abs(B[0] - A[n // 2]) < abs(B[-1] - A[n // 2]):
            B.append(A[n // 2])
        else:
            B.appendleft(A[n // 2])

    res = 0
    for i in range(1, n):
        res += abs(B[i] - B[i - 1])

    print(res)

if __name__ == '__main__':
    resolve()
