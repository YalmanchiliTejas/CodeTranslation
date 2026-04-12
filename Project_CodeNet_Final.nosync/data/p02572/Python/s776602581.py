MOD = 10**9 + 7
N = int(input())
A = [int(i) for i in input().split()]


S = [sum(A) % MOD]
for i in range(N):
    S.append(S[-1]-A[i])

ans = 0
for i in range(N-1):
    ans += A[i]*S[i+1]
    ans %= MOD
print(ans)
