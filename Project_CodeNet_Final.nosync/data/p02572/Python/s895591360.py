N = int(input())
A = list(map(int,input().split()))
mod = 1000000007
sum_A = 0
for i in range(N):
    A[i] = A[i] % mod
    sum_A += A[i]

ans = 0
for i in range(N-1):
    sum_A -= A[i]
    ans = (ans + (A[i] * sum_A) % mod) % mod

print(ans)
