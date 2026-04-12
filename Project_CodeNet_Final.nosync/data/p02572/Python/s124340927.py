N = int(input())
A = list(map(int, input().split()))
n = sum(A[1:])
ans = 0
mod = int(1e9+7)
for i in range(N-1):
    ans = (ans+(A[i]*n%mod))%mod
    n-=A[i+1]
print(ans)