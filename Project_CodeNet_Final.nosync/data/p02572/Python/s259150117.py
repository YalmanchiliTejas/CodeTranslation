N = int(input())
A = list(map(int,input().split()))
MOD = 10**9 + 7
S = [0]*N
S[0] = A[0]
for k in range(1,N):
    S[k] = S[k-1] + A[k]
ans = 0
for k in range(N-1,0,-1):
    ans += A[k]*S[k-1]
    ans %= MOD
print(ans)
