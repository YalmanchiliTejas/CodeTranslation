from sys import stdin
from itertools import accumulate
input = stdin.readline

n = int(input())
a = list(map(int,input().split()))
p = [0] + list(accumulate(a))
res = 0
for i in range(n-1,-1,-1):
    res += (a[i] * p[i])%(10**9 + 7)
print(res % (10**9 + 7))