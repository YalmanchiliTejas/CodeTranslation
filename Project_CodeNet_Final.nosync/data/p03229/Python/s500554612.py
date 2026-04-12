import sys

sys.setrecursionlimit(10 ** 5 + 10)


def input(): return sys.stdin.readline().strip()


def resolve():
    N = int(input())
    A = sorted([int(input()) for i in range(N)], reverse=True)
    c = 1
    cnt = 0
    if N % 2 == 0:
        print(sum(A[:N // 2 - 1]) * 2 + A[N // 2 - 1] - A[N // 2] - sum(A[N // 2 - 1 + 2:] * 2))
    else:
        ans1 = sum(A[:N // 2]) * 2 - sum(A[N // 2:N // 2 + 2]) - sum(A[N // 2 + 2:] * 2)
        ans2 = sum(A[:N // 2 - 1]) * 2 + sum(A[N // 2 - 1:N // 2 + 1]) - sum(A[N // 2 + 1:] * 2)
        print(max(ans1, ans2))


resolve()