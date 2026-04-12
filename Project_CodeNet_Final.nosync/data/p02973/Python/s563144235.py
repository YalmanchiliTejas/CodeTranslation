from collections import deque
import bisect
N = int(input())
A = []

for i in range(N):
    A.append(int(input()))

l = deque([])

for i in range(N):
    if l == []:
        l.append(A[i])
    else:
        index = bisect.bisect_right(l, A[i])
        index2 = bisect.bisect_left(l, A[i])
        if index == 0:
            l.appendleft(A[i])
        elif index != index2:
            if index2 == 0:
                l.appendleft(A[i])
            else:
                l[index2-1] = A[i]
        else:
            l[index-1] = A[i]

print(len(l))