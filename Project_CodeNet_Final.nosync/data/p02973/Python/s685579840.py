from sys import stdin, setrecursionlimit
from bisect import bisect_right

setrecursionlimit(10 ** 9)
INF = 1 << 60


def input():
    return stdin.readline().strip()


def main():
    N = int(input())
    A = tuple(int(input()) for _ in range(N))
    B = [-A[0]]

    for a in A[1:]:
        if a <= -B[-1]:
            B.append(-a)
        else:
            B[bisect_right(B, -a)] = -a

    print(len(B))


if __name__ == '__main__':
    main()
