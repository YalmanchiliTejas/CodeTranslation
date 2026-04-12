import bisect
import collections
import copy
import functools
import heapq
import math
import sys
from collections import deque
from collections import defaultdict
from fractions import Fraction
input = sys.stdin.readline
sys.setrecursionlimit(10**9)
INF = float("inf")

N,X,M = map(int,input().split())
A = [0]*100010
A[0] = X
d = defaultdict(int)
d[X] = 1
l = [X]

ans = X
for i in range(1,N):
    num = pow(A[i-1],2,M)
    l.append(num)
    if d[num] == 0:
        A[i] = num
        d[num] += 1
        ans += num
    else:
        kaburi = num
        break
else:
    print(ans)
    exit()

kaburi_index = l.index(kaburi)
loop_len = len(l)-1-kaburi_index
loop_sum = sum(l[kaburi_index:len(l)-1])

nokori = N-i
loop = nokori//loop_len
amari = nokori%loop_len

ans += loop_sum*loop
ans += sum(l[kaburi_index:kaburi_index+amari])
#print(A)

print(ans)