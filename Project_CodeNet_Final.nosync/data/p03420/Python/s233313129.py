import sys

input = sys.stdin.readline


def main():
    N, K = map(int, input().split())

    ans = 0
    for b in range(K + 1, N + 1):
        q, r = divmod(N, b)
        ans += (b - K) * q
        ans += max(0, min(b - 1, r) - max(1, K) + 1)

    print(ans)


if __name__ == "__main__":
    main()
