import sys
input = sys.stdin.readline


def main():
    n = int(input())
    A = list(map(int, input().split()))
    total = sum(A)
    mod = 10**9 + 7
    ans = 0
    for a in A[:-1]:
        total -= a
        ans += a * total
        ans %= mod

    print(ans)


if __name__ == "__main__":
    main()
