import sys


def input():
    return sys.stdin.readline().strip()


sys.setrecursionlimit(10 ** 9)


def main():
    A, B, C, X, Y = map(int, input().split())
    answer = float("inf")
    for c in range(10 ** 5 + 1):
        a = X - c
        b = Y - c
        money = c * C * 2
        a = A * max(a, 0)
        b = B * max(b, 0)
        if answer > money + a + b:
            answer = money + a + b
    print(answer)


if __name__ == "__main__":
    main()
