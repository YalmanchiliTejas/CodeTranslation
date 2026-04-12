import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    S = input().strip()

    if len(set(S)) == 1:
        print("No")
    else:
        print("Yes")


if __name__ == '__main__':
    main()

