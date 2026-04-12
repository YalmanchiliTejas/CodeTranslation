import bisect
import collections

N=int(input())
A=[int(input()) for i in range(N)]
B=[0 for i in range(N)]
C=sorted(A)
count=0
lst=collections.deque([])
for i in range(N):
    if A[i]==C[-1]:
        C.pop()
        if lst:
            lst.pop()
        else:
            count+=1
        continue
    idx=bisect.bisect_left(lst,A[i])-1
    #print(idx,lst,A[i])
    if idx<0:
        lst.appendleft(A[i])
        count+=1
    else:
        lst[idx]=A[i]

print(count)
