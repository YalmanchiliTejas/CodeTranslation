import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    N, X, M = map(int, readline().split())
    rem = N

    if X == 0:
        return print(0)

    seq = [0] * 200001
    seq[1] = X
    visited = set()
    visited.add(X)

    cur = X
    cnt = 1

    while cnt < N:
        cur = cur ** 2 % M
        cnt += 1
        if cur in visited:
            break
        elif cur == 0:
            return print(sum(seq))
        else:
            seq[cnt] = cur
            visited.add(cur)
    else:
        return print(sum(seq))

    first = seq.index(cur)
    l = cnt - first

    rem -= first
    p = rem // l
    q = rem % l

    ans = 0
    ans += sum(seq[:first])
    ans += p * sum(seq[first:])

    rem = q
    i = 0
    while i <= rem:
        x = seq[first + i]
        ans += x
        i += 1

    print(ans)


if __name__ == '__main__':
    main()
