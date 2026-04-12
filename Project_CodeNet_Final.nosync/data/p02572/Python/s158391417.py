N = int(input())

mod = 10**9 + 7

A = [int(i)%mod for i in input().split()]

S = [0]*N

ans = 0
for i in range(N-1):
    if i == 0:
        S[i] = sum(A) - A[i]
    else:
        S[i] = (S[i-1] - A[i])
    ans +=  (A[i]*S[i])%mod

print(ans%mod)
