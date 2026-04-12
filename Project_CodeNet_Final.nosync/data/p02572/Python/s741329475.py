import math
import sys
from itertools import permutations
input = sys.stdin.readline

p = 1000000007
n = int(input())
v = list(map(int, input().split()))

s = sum(v)
ss = 0
for i in range(n):
    ss += (v[i] * v[i])

ans = (s*s - ss) // 2
print(ans % p)