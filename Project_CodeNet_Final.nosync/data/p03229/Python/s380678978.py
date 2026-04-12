n=int(input())
d=[int(input()) for _ in range(n)]
from collections import deque
d.sort()
a=deque(d)

tmpl=a.popleft()
tmpr=tmpl
ans=0
i=0

while len(a)>0:
    #0 大きいほうから
    if i%4==0:
        tmp=a.pop()
        ans+=abs(tmpl-tmp)
        tmpl=tmp

    #1 大きいほうから
    elif i%4==1:
        tmp=a.pop()
        ans+=abs(tmpr-tmp)
        tmpr=tmp

    #2 小さいほうから
    elif i%4==2:
        tmp=a.popleft()
        ans+=abs(tmpl-tmp)
        tmpl=tmp


    #3 小さいほうから
    elif i%4==3:
        tmp=a.popleft()
        ans+=abs(tmpr-tmp)
        tmpr=tmp

    i+=1

res=ans
import copy
d.sort(reverse=True)
a= deque(copy.deepcopy(d))

tmpl=a.popleft()
tmpr=tmpl
ans=0
i=0

while len(a)>0:
    #0 大きいほうから
    if i%4==0:
        tmp=a.pop()
        ans+=abs(tmpl-tmp)
        tmpl=tmp

    #1 大きいほうから
    elif i%4==1:
        tmp=a.pop()
        ans+=abs(tmpr-tmp)
        tmpr=tmp

    #2 小さいほうから
    elif i%4==2:
        tmp=a.popleft()
        ans+=abs(tmpl-tmp)
        tmpl=tmp


    #3 小さいほうから
    elif i%4==3:
        tmp=a.popleft()
        ans+=abs(tmpr-tmp)
        tmpr=tmp

    i+=1

print(max(ans,res))




            


