import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(readline())
    a = list(map(int, readline().split()))
    a.sort(reverse=True)

    ans = 0
    flag = True

    while flag:
        flag = False
        cur = 0
        for i in range(n):
            if a[i] > (n - 1):
                cnt = (a[i] - (n - 1) + (n - 1)) // n
                ans += cnt
                cur += cnt
                a[i] -= (n + 1) * cnt
        for i in range(n):
            a[i] += cur
            if a[i] > n - 1:
                flag = True

    print(ans)


if __name__ == '__main__':
    main()
