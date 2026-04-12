def move(a, A, c):

  c.remove(a)
  if(c==[]):
    return 1
  if(not a in A):
    return 0
  sum = 0
  for i in A[a]:
    if(i in c):
      sum += move(i, A, list(c))

  return sum


N, M = map(int, input().split())

A = {}
c = []

for i in range(M):
  a, b = map(int, input().split())

  if(not a in c):
    c.append(a)
  if(not b in c):
    c.append(b)

  if(a in A):
    A[a].append(b)
  else:
    A[a] = [b]
  if(b in A):
    A[b].append(a)
  else:
    A[b] = [a]

print(move(1, A, c))

