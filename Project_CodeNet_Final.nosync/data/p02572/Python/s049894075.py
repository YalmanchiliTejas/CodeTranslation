import sys
input = sys.stdin.readline
from collections import *

N = int(input())
A = list(map(int, input().split()))
MOD = 10**9+7
ans = 0
acc = 0

for i in range(N):
    ans += A[i]*acc
    ans %= MOD
    acc += A[i]
    acc %= MOD

print(ans)