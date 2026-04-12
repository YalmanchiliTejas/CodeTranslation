from sys import stdin, setrecursionlimit
from bisect import bisect_left
from collections import deque

setrecursionlimit(10 ** 9)
INF = 1 << 60


def input():
    return stdin.readline().strip()


def main():
    N = int(input())
    A = tuple(int(input()) for _ in range(N))
    B =deque([A[0]])

    for a in A[1:]:
        if a <= B[0]:
            B.appendleft(a)
        else:
            B[bisect_left(B, a) - 1] = a

    print(len(B))


if __name__ == '__main__':
    main()
