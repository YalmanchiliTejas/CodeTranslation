import sys

input = sys.stdin.readline


def main():
    X = int(input())

    if X in [7, 5, 3]:
        ans = "YES"
    else:
        ans = "NO"

    print(ans)


if __name__ == "__main__":
    main()
