import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
# MOD = 10 ** 9 + 7
# INF = float("inf")


def main():
    n = int(input())
    x = n * 800
    y = (n // 15) * 200
    print(x - y)


if __name__ == '__main__':
    main()