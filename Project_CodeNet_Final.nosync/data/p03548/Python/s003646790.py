import sys

input = sys.stdin.readline


def main():
    X, Y, Z = map(int, input().split())

    ans = (X - Z) // (Y + Z)

    print(ans)


if __name__ == "__main__":
    main()
