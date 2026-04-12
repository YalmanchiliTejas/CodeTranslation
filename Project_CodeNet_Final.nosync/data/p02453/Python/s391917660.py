from bisect import *

n = int(input())
box = list(map(int, input().split()))
q = int(input())
for _ in range(q):
    k = int(input())
    print(bisect_left(box,k))
