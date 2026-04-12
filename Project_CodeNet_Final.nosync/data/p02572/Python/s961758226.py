from itertools import accumulate
N = int(input())
A = list(map(int,input().split()))
ans = 0
mod = 10**9 +7
accum = list(accumulate(A))

for i in range(N-1,0,-1):
    ans += A[i]*accum[i-1]%mod
    ans %= mod
print(ans)
