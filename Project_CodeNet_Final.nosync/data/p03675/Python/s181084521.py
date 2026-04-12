read = lambda: map(int, input().split())
n = int(input())
a = list(read())
from collections import deque
b = deque()
x = 1
for i in range(n):
    if x: b.append(a[i])
    else: b.appendleft(a[i])
    x ^= 1
ans = list(b)
if not x: ans = ans[::-1]
print(*ans)