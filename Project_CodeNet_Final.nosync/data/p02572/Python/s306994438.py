
from itertools import accumulate
N = int(input())
A = list(map(int, input().split()))
B = list(accumulate(A))
mod = 10**9+7
ans = 0
sumA = sum(A)

for i in range(N-1):
    ans += A[i] * (sumA-B[i]) % mod
    ans = ans%mod
    
print(ans)


