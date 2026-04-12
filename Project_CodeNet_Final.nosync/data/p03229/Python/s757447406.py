from heapq import heappop, heappush, heapify
from collections import deque
n = int(input())
li_a = []
for i in range(n):
  li_a.append(int(input()))
m1 = []
M1 = []
m2 = []
M2 = []
for i in li_a:
    heappush(m1, i)
    heappush(M1, -i)
    heappush(m2, i)
    heappush(M2, -i)
l1 = deque()
l2 = deque()
if n % 2 == 0:
    l1.append(-heappop(M1))
    l2.append(heappop(m2))
    while True:
        l1.append(heappop(m1))
        l2.append(-heappop(M2))
        if len(l1) == n:
            break
        l1.appendleft(heappop(m1))
        l2.appendleft(-heappop(M2))
        if len(l1) == n:
            break
        else:
            l1.append(-heappop(M1))
            l2.append(heappop(m2))
            if len(l1) == n:
                break
            l1.appendleft(-heappop(M1))
            l2.appendleft(heappop(m2))
            if len(l1) == n:
                break
if n % 2 == 1:
    l1.append(-heappop(M1))
    l2.append(heappop(m2))
    while True:
        l1.append(heappop(m1))
        l2.append(-heappop(M2))
        l1.appendleft(heappop(m1))
        l2.appendleft(-heappop(M2))
        if len(l1) == n:
            break
        else:
            l1.append(-heappop(M1))
            l1.appendleft(-heappop(M1))
            l2.append(heappop(m2))
            l2.appendleft(heappop(m2))
            if len(l1) == n:
                break
ans1 = 0
ans2 = 0
for i in range(n-1):
    ans1 += abs(l1[i+1]-l1[i])
    ans2 += abs(l2[i+1]-l2[i])
print(max(ans1, ans2))