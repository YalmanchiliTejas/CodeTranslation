# ARC091D - Remainder Reminder
def main():
    # a, b := b ≥ K + 1
    N, K = tuple(map(int, input().split()))
    ans = 0
    for b in range(K + 1, N + 1):
        ans += N // b * (b - K)
        if K:
            ans += max(0, (N % b) - K + 1)
        else:
            ans += N % b
    print(ans)


if __name__ == "__main__":
    main()