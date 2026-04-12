import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(readline())
    h = list(map(int, readline().split()))

    cur = h[0]
    ans = 1

    for i in range(1, n):
        if h[i] >= cur:
            ans += 1
            cur = h[i]

    print(ans)

if __name__ == '__main__':
    main()
