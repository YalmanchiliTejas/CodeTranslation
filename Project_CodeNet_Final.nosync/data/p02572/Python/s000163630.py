N = int(input())
A = list(map(int, input().split()))
mod = int(1e9) + 7
cA = [A[0]]
ans = 0
for i in range(1, N):
    cA.append(cA[-1] + A[i])
for i in range(N-1):
    ans += A[i] * ((cA[-1] - cA[i])%mod)
    ans %= mod
print(ans)