N = int(input())
A = list(map(int,input().split()))

mod = 10**9 + 7
ans = 0
A_sum = [0]

for i in range(N):
    A_sum.append(A_sum[-1] + A[i])

for i in range(N-1):
    ans += A[i] * (A_sum[N] - A_sum[i+1])
    ans %= mod

print(ans)