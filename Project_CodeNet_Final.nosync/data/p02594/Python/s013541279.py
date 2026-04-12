import sys

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    X = int(input())
    if X >= 30:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
