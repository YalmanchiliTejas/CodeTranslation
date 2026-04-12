#E問題
import heapq
import bisect
N = int(input())
A = [int(input()) for i in range(N)]
A = A[::-1]

C = []
for i in range(N):
    if i == 0:
        C.append(A[i])
    else:
        li = bisect.bisect_right(C,A[i])
        if li == len(C):
            C.append(A[i])
        else:
            C[li] = A[i]
    
print(len(C))