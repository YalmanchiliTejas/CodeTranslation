N, K = map(int, input().split())
ans = 0

if K == 0:
    print(N ** 2)
else:
    # b を固定？
    for b in range(1, N + 1):
        if b - 1 < K: continue
        ans += (b - K) * (N // b)
        ans += max(N % b - K + 1, 0)
        # print(b, ans)

    print(ans)