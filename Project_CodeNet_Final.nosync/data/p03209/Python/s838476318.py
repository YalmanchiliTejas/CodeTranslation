import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n, x = list(map(int, readline().split()))
    l = [0] * (n + 1)
    b = [0] * (n + 1)

    l[0] = 1
    b[0] = 1

    for i in range(1, n + 1):
        l[i] = 2 * l[i - 1] + 3
        b[i] = 2 * b[i - 1] + 1

    ans = 0
    rem = x
    level = n

    while rem and level > 0:
        if rem >= l[level - 1] + 2:
            ans += b[level - 1] + 1
            rem -= (l[level - 1] + 2)
            level -= 1
        elif rem == l[level - 1] + 1:
            rem -= (l[level - 1] + 1)
            ans += b[level - 1]
        else:
            rem -= 1
            level -= 1

    if level == 0 and rem:
        ans += 1

    print(ans)


if __name__ == '__main__':
    main()
