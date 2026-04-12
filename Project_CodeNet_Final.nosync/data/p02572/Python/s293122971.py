n = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7
cum = [A[0]]
for i in range(1, n):
    cum.append(cum[-1] + A[i])
ans = 0
for i in range(n-1):
    ans += A[i] * (cum[-1] - cum[i])
    ans %= mod
print(ans)