import sys
input = sys.stdin.readline


def main():
    a, b, c, x, y = map(int, input().split())
    c *= 2
    res1 = a * x + b * y
    res2 = c * max(x, y)
    res3 = c * x + max(0, y-x) * b
    res4 = c * y + max(0, x-y) * a
    print(min([res1, res2, res3, res4]))


if __name__ == "__main__":
    main()
