
from collections import deque

n=int(input())
a=[]
for i in range(n):
    A=int(input())
    a.append(A)
l=deque([a[0]])
for i in range(1,n):
    if l[0]>=a[i]:
        l.appendleft(a[i])
    elif l[-1]<a[i]:
        l[-1]=a[i]
    else:
        p=0
        q=len(l)-1
        while q-p!=1:
            if l[(p+q)//2]>=a[i]:
                q=(p+q)//2
            else:
                p=(p+q)//2
        l[p]=a[i]
print(len(l))