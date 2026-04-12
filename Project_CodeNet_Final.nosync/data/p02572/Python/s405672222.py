N = int(input())
A = list(map(int, input().split()))
MOD = 10**9 + 7

import copy
B = copy.copy(A)
C = sum(B)
ans = 0

for i in range(N-1):
    C = (C - B[i]) % MOD
    ans += A[i] * C % MOD
    ans = ans % MOD
print(ans)