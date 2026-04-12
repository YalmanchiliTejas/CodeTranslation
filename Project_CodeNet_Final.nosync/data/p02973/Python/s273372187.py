import sys
from bisect import bisect_left
read = sys.stdin.read
readline = sys.stdin.readline


def main():
    N, *A = map(int, read().split())

    a = [-1] * N

    for i in A:
        n = bisect_left(a, i)
        a[n - 1] = i

    print(N - a.count(-1))


if __name__ == '__main__':
    main()