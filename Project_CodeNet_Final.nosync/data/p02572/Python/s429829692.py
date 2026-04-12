N = int(input())
A = list(map(int, input().split()))
mod = 1000000007
ans = 0
cs = [0]*N
cs[0] = A[0]

for i in range(1, N):
    cs[i] = cs[i-1] + A[i]

for i in range(N-1):
    n = A[i] * (cs[-1] - cs[i]) % mod
    ans += n
    ans %= mod

print(ans)