N = int(input())
A = [0] + list(map(int, input().split()))
mod = 10**9 + 7

t = sum(A)
ans = 0
for i in range(1,N+1):
    t -= A[i]
    ans += A[i] * t % mod
print(ans % mod)