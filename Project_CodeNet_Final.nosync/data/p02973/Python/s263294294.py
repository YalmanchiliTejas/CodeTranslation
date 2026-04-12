import sys
from bisect import bisect_right

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60


def main():
    N, *A = map(int, read().split())

    dp = [A.pop()]
    for a in reversed(A):
        if a >= dp[-1]:
            dp.append(a)
        else:
            dp[bisect_right(dp, a)] = a

    print(len(dp))
    return


if __name__ == '__main__':
    main()
