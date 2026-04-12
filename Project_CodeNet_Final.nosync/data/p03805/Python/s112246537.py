N, M = map(int, input().split())
e=[[] for i in range(N+1)]
for i in range(M):
    a, b = map(int, input().split())
    e[a].append(b)
    e[b].append(a)

from collections import deque
def dws(st):
  ret = 0
  q = deque([])   # キュー
  q.append(st)
  while len(q) > 0:
    p = q.popleft()
    if len(p)==N:
      ret += 1
    else:
      for a in e[p[-1]]:
        if not a in p:
          q.append(p+[a])    # キュー追加
  return ret
print(dws([1]))