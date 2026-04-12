import bisect
from collections import deque

N = int(input())

tops = deque() 

for i in range(N):
    a = int(input())
    p = bisect.bisect_left(tops, a)
    
    if p == 0:
        tops.appendleft(a)
    else:    
        tops[p-1] = a
        
print(len(tops))
