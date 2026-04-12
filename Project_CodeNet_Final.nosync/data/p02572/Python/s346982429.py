N = int(input())
A = [int(a) for a in input().split()]
cum_A = [0] * N
cum_A[0] = A[0]
for i in range(1, N):
    cum_A[i] = cum_A[i - 1] + A[i]

ans = 0
for i in range(N - 1):
    inner_sum = cum_A[-1] - cum_A[i]
    ans += A[i] * inner_sum

print(ans % (10**9 + 7))
