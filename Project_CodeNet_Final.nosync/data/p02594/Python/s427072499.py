import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    N = int(input())
    if N >= 30:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    main()

