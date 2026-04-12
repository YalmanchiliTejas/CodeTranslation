INF = 10 ** 9 + 7
N = int(input())
A = list(map(int, input().split()))
rui = [0] * (N + 1)
for i in range(N):
    rui[i + 1] = A[i] + rui[i]

ans = 0
for i in range(N - 1):
    ans += (rui[N] - rui[i + 1]) * A[i]
    ans %= INF
print(ans % INF)
