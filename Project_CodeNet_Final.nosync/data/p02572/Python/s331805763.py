N = int(input())
A = list(map(int,input().split()))

MOD = 10**9+7

ans = sum(A)%MOD
ans *= sum(A)
ans %= MOD

temp = 0
for i in range(N):
    X = A[i]%MOD
    Y = X**2
    Y %= MOD
    temp += Y
    

    
print(((ans-temp)*pow(2, MOD-2, MOD)%MOD))