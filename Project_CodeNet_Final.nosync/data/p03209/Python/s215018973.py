import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_nl = lambda: list(map(int, readline().split()))
in_na = lambda: map(int, read().split())
in_s = lambda: readline().rstrip().decode('utf-8')

sys.setrecursionlimit(100000)

N, X = in_nn()

blen = [0] * (N + 1)
blen[0] = 1
for i in range(N):
    blen[i + 1] = blen[i] * 2 + 3

pcount = [0] * (N + 1)
pcount[0] = 1
for i in range(N):
    pcount[i + 1] = pcount[i] * 2 + 1


def count(L, X):

    if L == 0:
        return 1

    if X == 1:
        return 0

    ret = 0
    if X <= blen[L] // 2:
        ret += count(L - 1, X - 1)
    else:
        ret += pcount[L - 1] + 1
        if X > blen[L] // 2 + 1:
            X -= blen[L] // 2 + 1
            X = min(X, blen[L - 1])
            ret += count(L - 1, X)

    return ret


def main():

    ans = count(N, X)
    print(ans)


if __name__ == '__main__':
    main()
