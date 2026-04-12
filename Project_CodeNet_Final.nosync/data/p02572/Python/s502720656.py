MOD = 10**9+7
N = int(input())
A = list(map(int,input().split()))
ruiseki = [A[i] for i in range(N)]

for i in range(1,N):
    ruiseki[i]=ruiseki[i]+ruiseki[i-1]

ans = 0
for i in range(1,N):
    ans =(ans + ((A[i]%MOD)*(ruiseki[i-1]%MOD))%MOD)%MOD

print(ans)
