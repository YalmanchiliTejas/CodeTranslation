import sys

input = sys.stdin.readline


def main():
    print("YES" if int("".join(input().split())) % 4 == 0 else "NO")


if __name__ == "__main__":
    main()
