n=int(input())
a=[]
for i in range(n):
    aa=int(input())
    a.append(aa)
from collections import deque
a.sort()
a=deque(a)

omi=a.popleft()
oma=a.pop()
ans=abs(oma-omi)
ret=True

while len(a)>1:
    mi=a.popleft()
    ma=a.pop()

    if ret:
        mi,ma=ma,mi

    ans+=abs(omi-mi)+abs(oma-ma)
    omi,oma=mi,ma
    ret = not ret

if len(a)==1:
    aa=a.pop()
    ans+=max(abs(omi-aa),abs(oma-aa))

print(ans)