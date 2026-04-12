N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7

row_sum = sum(A)
ans = 0
for i in range(N):
    ans += A[i] * row_sum - A[i]*A[i]
print(ans // 2 % mod)