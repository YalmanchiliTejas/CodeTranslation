import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    a, b, c = input().split()
    x = int(a + b + c)

    if x % 4 == 0:
        print("YES")
    else:
        print("NO")


if __name__ == '__main__':
    main()
