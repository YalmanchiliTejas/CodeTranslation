from collections import deque

n = int(input())
l = list(map(int, input().split()))
d = deque()

for i in range(n):
  if (i % 2 == 0):
    d.appendleft(l[i])
  else:
    d.append(l[i])

if (n % 2 == 0):
  d = reversed(d)

print(" ".join(map(str, d)))
