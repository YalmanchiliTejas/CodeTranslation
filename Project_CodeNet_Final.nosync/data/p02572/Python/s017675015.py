N = int(input())
A = list(map(int, input().split()))
mod = 10**9 +7
ans = 0

S = [0]*N

for i in range(1,N):
    S[i] = (A[N-i]+S[i-1])%mod

for j in range(1,N):
    ans += (S[j]*A[N-1-j])%mod
    ans = ans%mod

print(ans%mod)