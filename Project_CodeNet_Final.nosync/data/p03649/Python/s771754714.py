import sys
from heapq import heapify, heappop, heappush

read = sys.stdin.read
readline = sys.stdin.readline

N, *a = map(int, read().split())
heap = [-i for i in a]
heapify(heap)
answer = 0
while True:
    if -heap[0] + answer < N:
        break
    i = -heappop(heap) + answer
    cnt = (i + 1) // (N + 1)
    i -= answer + cnt * (N + 1)
    answer += cnt
    heappush(heap, -i)
print(answer)
