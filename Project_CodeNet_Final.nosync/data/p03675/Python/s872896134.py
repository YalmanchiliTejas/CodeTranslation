from collections import *
n=int(input())
a=list(map(int,input().split()))
b=deque()
for i in range(n):
    if i%2==0:
        b.append(a[i])
    else:
        b.appendleft(a[i])
b=list(b)
if n%2==0:
    print(*b)
else:
    print(*b[::-1])