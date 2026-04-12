N=int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7
S = [0 for i in range(N)]
S[0] = A[0] 
for i in range(1,N):
    S[i] = (S[i-1]+ A[i])%mod

ans = 0
for i in range(N-1):
    ans = (ans + S[i] * A[i+1])%mod

print(ans%mod)

