from collections import deque
n=int(input())
a=list(map(str,input().split()))
d=deque()
for i in range(n):
    if i%2==0:
        d.appendleft(a[i])
    else:
        d.append(a[i])
d=list(d)
if n%2==0:
    d=d[::-1]
print(" ".join(d))