N = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7
s = sum(A[1:])
ans = 0
for i in range(N-1):
    ans += (A[i] * s) % mod
    s -= A[i+1]
print(ans%mod)