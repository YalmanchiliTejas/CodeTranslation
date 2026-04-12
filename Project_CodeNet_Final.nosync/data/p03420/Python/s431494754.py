import sys

sys.setrecursionlimit(10 ** 5 + 10)


def input(): return sys.stdin.readline().strip()


def resolve():
    N, K = map(int, input().split())
    cnt = 0

    if K == 0:
        print(N ** 2)
    else:
        for b in range(K + 1, N + 1):
            p, mod = divmod((N + 1), b)

            cnt += p * (b - K)
            if mod != 0:
                if N >= K + p * b:
                    cnt += N - (K + p * b)+1

        print(cnt)


resolve()