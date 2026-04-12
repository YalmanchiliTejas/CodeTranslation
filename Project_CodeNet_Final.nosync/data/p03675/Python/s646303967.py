n = int(input())
a = list(map(int,input().split()))

from collections import deque

Q=deque([])

if n%2==0:
    for i in range(n):
        if i%2==0:
            Q.append(a[i])
        else:
            Q.appendleft(a[i])
else:
    for i in range(n):
        if i%2==0:
            Q.appendleft(a[i])
        else:
            Q.append(a[i])

ans = []

for i in range(n):
    ans.append(Q.popleft())

print(*ans)