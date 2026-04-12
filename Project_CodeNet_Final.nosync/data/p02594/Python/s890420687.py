import sys


def input():
    return sys.stdin.readline().strip()


sys.setrecursionlimit(20000000)

MOD = 10 ** 9 + 7
INF = float("inf")


def main():
    X = int(input())
    if X >= 30:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
