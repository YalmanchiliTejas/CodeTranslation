from collections import deque
n = int(input())
a = sorted(int(input()) for _ in range(n))
d = deque(a)
l = deque([])
bit = 0
if len(d)%2==0:
    while d:
        dmi = d.popleft()
        dma = d.pop()
        if bit==1:
            l.appendleft(dmi)
            l.append(dma)
            bit = 0
        else:
            l.append(dmi)
            l.appendleft(dma)
            bit = 1
else:
    while len(d)!=1:
        dmi = d.popleft()
        dma = d.pop()
        if bit==1:
            l.appendleft(dmi)
            l.append(dma)
            bit = 0
        else:
            l.append(dmi)
            l.appendleft(dma)
            bit = 1
    last = d.pop()
    if abs(l[0]-last)<abs(l[-1]-last):
        l.append(last)
    else:
        l.appendleft(last)
ans = 0
for i in range(len(l)-1):
  ans += abs(l[i+1] - l[i])
  
print(ans)