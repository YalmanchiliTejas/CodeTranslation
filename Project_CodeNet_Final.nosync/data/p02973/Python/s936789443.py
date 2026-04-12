import sys
from bisect import bisect_right

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, *A = map(int, read().split())

    vec = [A[-1]]
    for a in reversed(A[:-1]):
        if a >= vec[-1]:
            vec.append(a)
        else:
            vec[bisect_right(vec, a)] = a

    print(len(vec))
    return


if __name__ == '__main__':
    main()
