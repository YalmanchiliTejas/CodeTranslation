import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60


def main():
    N, X, M = map(int, readline().split())

    a = X
    ans = 0

    A = []
    index = [-1] * M
    n = 0

    while index[a] == -1 and n < N:
        index[a] = n
        A.append(a)
        n += 1
        a = (a * a) % M

    if n == N - 1:
        print(sum(A))
        return

    ans = sum(A[: index[a]])
    rest = N - index[a]
    cycle = sum(A[index[a] : n])
    remainder = sum(A[index[a] : index[a] + rest % (n - index[a])])

    ans += cycle * (rest // (n - index[a])) + remainder
    print(ans)

    return


if __name__ == '__main__':
    main()
