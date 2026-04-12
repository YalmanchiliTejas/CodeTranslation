from collections import *
a = sorted(int(input()) for _ in range(int(input())))
q = deque(a)
rq = deque([q.popleft()])
while q:
    rq.appendleft(q.pop())
    if q: 
        rq.append(q.pop())
    if q:
        rq.appendleft(q.popleft())
    if q: 
        rq.append(q.popleft())
r1 = sum(abs(i-j) for i, j in zip(rq, list(rq)[1:]))

q = deque(a[::-1])
rq = deque([q.popleft()])
while q:
    rq.appendleft(q.pop())
    if q: 
        rq.append(q.pop())
    if q:
        rq.appendleft(q.popleft())
    if q: 
        rq.append(q.popleft())
r2 = sum(abs(i-j) for i, j in zip(rq, list(rq)[1:]))
print(max(r1, r2))