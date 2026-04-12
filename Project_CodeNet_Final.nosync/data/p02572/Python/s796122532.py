#ここまでテンプレ
from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10 ** 7)

n = int(stdin.readline().rstrip())
a = list(map(int,stdin.readline().rstrip().split()))

point = 0
mod = 10**9+7

from itertools import accumulate

li = list(accumulate(a))

for i,j in enumerate(a):
    point += j*(li[-1]-li[i])%mod

print(point%mod)