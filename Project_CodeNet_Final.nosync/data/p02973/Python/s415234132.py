import collections
import sys
import bisect
input = sys.stdin.readline
N = int(input())
queue = collections.deque()
queue.append(int(input()))
for i in range(N-1):
    a = int(input())
    index = bisect.bisect_left(queue, a)
    if index == 0:
        queue.appendleft(a)
    else:
        queue[index-1] = a

print(len(queue))
