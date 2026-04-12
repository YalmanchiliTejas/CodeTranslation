N = int(input())
A = list(map(int, input().split()))

c_sum = sum(A)
mod = 10**9 + 7
ans = 0

for i in range(N-1):
    c_sum -= A[i]
    ans += A[i] * c_sum % mod
ans %= mod
print(ans)