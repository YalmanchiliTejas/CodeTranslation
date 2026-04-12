n = int(input())
a = sorted([int(input()) for i in range(n)])

m = n//2
a1 = a[:m]
a2 = a[:m-1:-1]
if n%2==1:a1.append(a[m])

from collections import deque
l = deque([])

for i in range(m):
    if i%2==0:
        l.append(a1[i])
        l.appendleft(a2[i])
    else:
        l.append(a2[i])
        l.appendleft(a1[i])

if n%2==1:
    if abs(l[0]-a1[-1])>abs(l[-1]-a1[-1]):
        l.appendleft(a1[-1])
    else:
        l.append(a1[-1])

ans = 0
for i in range(n-1):
    ans += abs(l[i]-l[i+1])

print(ans)