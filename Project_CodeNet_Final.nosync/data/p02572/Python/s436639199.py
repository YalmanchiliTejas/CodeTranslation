MOD = 10**9 + 7
import sys
from itertools import accumulate
input = sys.stdin.readline
N = int(input())
A = list(map(int,input().split()))

cs = accumulate(A)

ans = 0
for s,t in zip(cs, A[1:]):
    ans += s * t
    ans %= MOD

print(ans)



