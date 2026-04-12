import sys

INPUT = lambda: sys.stdin.readline().rstrip()
INT = lambda: int(INPUT())

sys.setrecursionlimit(10 ** 9)


def main():
    X = INT()
    print("YES" if X == 3 or X == 5 or X == 7 else "NO")


if __name__ == '__main__':
    main()