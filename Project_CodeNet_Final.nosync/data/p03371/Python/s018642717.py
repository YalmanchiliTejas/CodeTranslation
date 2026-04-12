import sys
input = sys.stdin.readline
# sys.setrecursionlimit(10 ** 6)
# MOD = 10 ** 9 + 7
# INF = float("inf")


def main():
    a, b, c, x, y = map(int, input().split())
    case1 = a * x + b * y
    if x - y > 0:
        case2 = c * 2 * y + a * (x - y)
    else:
        case2 = c * 2 * y
    if y - x > 0:
        case3 = c * 2 * x + b * (y - x)
    else:
        case3 = c * 2 * x
    print(min(case1, case2, case3))


if __name__ == '__main__':
    main()