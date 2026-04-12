import sys

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    N, X, M = map(int, readline().split())
    L = [X]
    A = X
    # used: 何回目で出てきたか
    used = [-1] * M
    used[X] = 0
    i = 1
    while True:
        i += 1
        A = A * A % M
        if used[A] == -1:
            used[A] = i
            L.append(A)
        else:
            i
            break
    i2 = L.index(A) + 1
    l = len(L)
    if l >= N:
        ans = sum(L[:N])
    else:
        ans = sum(L)
        ans += sum(L[i2 - 1:]) * ((N - l) // (i - i2))
        ans += sum(L[i2 - 1:i2 - 1 + ((N - l) % (i - i2))])
    print(ans)


if __name__ == '__main__':
    main()
