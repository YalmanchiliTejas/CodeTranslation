N = int(input())
A = list(map(int,input().split()))
MOD = 10**9+7
S = sum(A)
S %= MOD
S2 = (S**2)%MOD 
M = 0
for i in range(N):
    M += A[i]**2
    M %= MOD
print((S2-M)*pow(2,MOD-2,MOD) %MOD)