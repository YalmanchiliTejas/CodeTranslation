n = int(input())
A = list(map(int, input().split()))

AA = sum(A)
ans = 0
mod = 10**9 + 7
for i in range(n):
    ans += (A[i] * (AA - A[i]))
print((ans // 2) % mod)
