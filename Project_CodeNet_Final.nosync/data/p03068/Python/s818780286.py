import sys

input = sys.stdin.readline


def main():
    N = int(input())
    S = input().rstrip()
    K = int(input())

    ans = ""
    T = S[K - 1]
    for s in S:
        if s == T:
            ans = ans + T
        else:
            ans = ans + "*"

    print(ans)


if __name__ == "__main__":
    main()
