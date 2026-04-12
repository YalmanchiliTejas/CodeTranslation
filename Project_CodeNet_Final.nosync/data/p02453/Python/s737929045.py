import sys
from bisect import bisect_left

n = int(input())
a = tuple(map(int,sys.stdin.readline().split()))
q = int(input())

l = len(a)
for k in sys.stdin:
    k = int(k.strip())
    if k > a[-1]:print(l)
    else:
        print(bisect_left(a,k))
