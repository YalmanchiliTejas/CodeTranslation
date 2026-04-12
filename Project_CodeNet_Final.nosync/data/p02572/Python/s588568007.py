N = int(input())
A = list(map(int, input().split()))
s = [0]*(N+1)
for i in range(N):
    s[i+1] = s[i] + A[i]

mod = 10**9 + 7
ans = 0
for i in range(N-1):
    ans += A[i] * (s[-1] - s[i+1])
    ans %= mod

print(ans)
