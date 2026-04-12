from bisect import *

N = int(input())
A = []
for i in range(N):
    A.append(-int(input()))

inf = float('inf')
ret = [inf] * N

ind = 0
for elem in A:
    i = bisect_right(ret, elem)
    ret[i] = elem
    if ind < i:
        ind = i

print(ind+1)
        
