N = int(input())
A = list(map(int,input().split()))
cum = [0] * (N-1)
now = 0
for i in range(N-1):
    now += A[-(i+1)]
    cum[i] = now
ans = 0
for i in range(N-1):
    ans += A[i] * cum[-(i+1)]
    ans %= (10**9+7)
print(ans % (10**9+7))