from itertools import accumulate

N = int(input())
A = list(map(int,input().split()))
acc = list(accumulate(A))
mod = 10**9+7

ans = 0
for i in range(N-1):
    tmp = acc[-1] - acc[i]
    ans += (A[i]*tmp)%mod
    ans %= mod
print(ans)