mod = 10**9+7
N = int(input())
A = list(map(int,input().split()))
AA = 0
for i in range(N):
    AA += A[i]**2
    AA %= mod
print((sum(A)**2-AA)*pow(2,mod-2,mod) % mod)