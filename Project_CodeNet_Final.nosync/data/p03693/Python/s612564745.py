import sys

input = sys.stdin.readline


def main():
    r, g, b = map(int, input().split())

    num = int("".join(map(str, [r, g, b])))

    if num % 4 == 0:
        ans = "YES"
    else:
        ans = "NO"
    print(ans)


if __name__ == "__main__":
    main()
