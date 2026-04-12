N, K = map(int, input().split())

if K == 0:
    print(N ** 2)
else:
    ans = 0
    for b in range(K + 1, N + 1):
        n_groups = N // b
        rest = N % b
        ans += n_groups * (b - K) + max(0, rest - K + 1)

    print(ans)
