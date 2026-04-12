import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    x, y, z = map(int, readline().split())

    rem = x - z
    ans = 0
    while rem >= (y + z):
        rem -= (y + z)
        ans += 1

    print(ans)


if __name__ == '__main__':
    main()
