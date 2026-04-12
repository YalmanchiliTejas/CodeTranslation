N = int(input())
A = list(map(int,input().split()))

MOD = 10**9+7
S = sum(A)
ans = 0

for i in range(N-1):
    S -= A[i]
    ans = (ans + S*A[i])%MOD
    
print(ans)