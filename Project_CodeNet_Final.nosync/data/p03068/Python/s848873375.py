import sys

input = sys.stdin.readline


def main():
    n = int(input())
    s = input().rstrip()
    k = int(input())
    print("".join([c if c == s[k - 1] else "*" for c in s]))


if __name__ == "__main__":
    main()
