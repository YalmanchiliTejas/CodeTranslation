import sys

input = sys.stdin.readline


def main():
    S = input().rstrip()

    if S.count("AC") > 0:
        ans = "Yes"
    else:
        ans = "No"

    print(ans)


if __name__ == "__main__":
    main()
