from collections import deque
N, M = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(M)]
stack = deque([[1]])
seen = deque([])
c = 0
while stack:
  x = stack.pop()
  seen.append(x)
  if len(x)==N:
    c += 1
    continue
  p = x[-1]
  A = []
  for l in L:
    if l[0]==p:
      A.append(l[1])
    if l[1]==p:
      A.append(l[0])
  A = [a for a in A if a not in x]
  for a in A:
    if x+[a] in (seen or stack):
      continue
    else:
      stack.append(x+[a])
print(c)