from itertools import accumulate
N = int(input())
A = list(map(int, input().split()))
S = list(accumulate(A))
MOD = 10**9 + 7
res = 0
for i in reversed(range(1,N)):
    res += S[i-1]*A[i]
    res %= MOD
print(res)