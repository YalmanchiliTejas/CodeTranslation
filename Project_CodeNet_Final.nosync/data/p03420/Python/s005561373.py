# ARC091D - Remainder Reminder
def main():
    N, K = tuple(map(int, input().split()))
    if K == 0:
        print(N ** 2)
    else:
        ans = sum(
            N // i * (i - K) + max(0, (N % i) - K + 1) for i in range(K + 1, N + 1)
        )
        print(ans)


if __name__ == "__main__":
    main()