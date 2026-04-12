from collections import deque
import bisect
N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

Colors = deque()
Colors.append(A[0])

for i in range(1, N):
    if Colors[0] >= A[i]:
        Colors.appendleft(A[i])
    else:
        idx = bisect.bisect_left(Colors, A[i])
        Colors[idx-1] = A[i]
print(len(Colors))

