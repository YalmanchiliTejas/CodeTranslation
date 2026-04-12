import bisect
import collections

N=int(input())

line=collections.deque()

for _ in range(N):
    A=int(input())
    index=bisect.bisect_left(line,A)
    if index==0:
        line.appendleft(A)
    else:
        line[index-1]=A
    #print(line)
    
    #print(line)

print(len(line))
