MOD = 10**9+7
N = int(input())
*A, = map(int, input().split())
a = [0]*N
a[-1] = A[-1]
for i in range(N-2, -1, -1):
    a[i] = A[i]+a[i+1]

ans = 0
for i in range(N-1):
    ans += A[i]*a[i+1]
    ans %= MOD
print(ans)
