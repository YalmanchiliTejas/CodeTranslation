N = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7
ans = 0

A_sum = [A[0] for i in range(N)]
for i in range(1, N):
    A_sum[i] = A_sum[i-1] + A[i]

for i in range(1, N):
    ans += A[i] * A_sum[i-1]
    ans %= mod

print(ans)
