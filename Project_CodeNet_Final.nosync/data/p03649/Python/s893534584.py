import heapq
import math
N = int(input())
a = list(map(int, input().split()))


hq = [-x for x in a]
heapq.heapify(hq)
ans = 0
while(hq[0] < 1-N):
    x = heapq.heappop(hq)
    x = -x
    k = x // N
    x %= N
    ans += k

    for i in range(N-1):
        hq[i] -= k
    heapq.heappush(hq, -x)

print(ans)
