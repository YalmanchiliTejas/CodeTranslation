import sys
from bisect import bisect_right

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60


def main():
    N, *A = map(int, read().split())

    vec = [INF] * N
    for a in reversed(A):
        vec[bisect_right(vec, a)] = a

    print(N - vec.count(INF))
    return


if __name__ == '__main__':
    main()
