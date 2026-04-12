from itertools import accumulate
N = int(input())
A = list(map(int, input().split()))
A.reverse()
sumA=[0,]+list(accumulate(A))
mod=10**9+7
ans=0
for a, s in zip(A, sumA):
    ans+=((a%mod)*(s%mod))%mod
    ans%=mod
print(ans)