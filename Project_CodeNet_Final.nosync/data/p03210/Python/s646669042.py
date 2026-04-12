import sys

input = sys.stdin.readline


def main():
    print("YES" if int(input()) in (7, 5, 3) else "NO")


if __name__ == "__main__":
    main()
