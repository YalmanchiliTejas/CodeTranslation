N = int(input())
A = list(map(int, input().split()))


accum = [0] * (N+1)
for i in range(N):
    accum[i+1] = (accum[i] + A[i]) % (10**9+7)

ans = 0
for i in range(N-1):
    ans += (A[i] * (accum[-1] - accum[i+1])) % (10**9+7)

print(ans % (10**9+7))
