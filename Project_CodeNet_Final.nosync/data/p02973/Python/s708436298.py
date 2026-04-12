import sys
from bisect import bisect_left
from collections import deque

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    color = deque([A[0]])

    for i in range(1, N):
        idx = bisect_left(color, A[i])
        if idx == 0:
            color.appendleft(A[i])
        else:
            color[idx - 1] = A[i]

    print(len(color))


if __name__ == "__main__":
    main()
