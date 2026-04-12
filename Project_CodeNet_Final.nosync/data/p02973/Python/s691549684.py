from bisect import bisect_left
from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
A = [int(input()) for _ in range(N)]

q = deque([A[0]])
for i in range(1,N):
    insert_index = bisect_left(q,A[i])
    if insert_index == 0:
        q.appendleft(A[i])
    else:
        q[insert_index-1] = A[i]

print(len(q))
