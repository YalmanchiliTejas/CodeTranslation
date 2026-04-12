import sys
input = sys.stdin.readline


def main():
    N, M = map(int, input().split())
    print("Yes") if N == M else print("No")


if __name__ == '__main__':
    main()
