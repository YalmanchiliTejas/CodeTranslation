import itertools
n, m = map(int, input().split(" "))
d = {}
for i in range(1, n+1):
  d[i] = []

for _ in range(m):
  a, b = map(int, input().split(" "))
  d[a].append(b)
  d[b].append(a)
  

cnt = 0
for iter in itertools.permutations(range(2, n+1)):
  bp = 0
  for i, num in enumerate(iter):
    if i == 0:
      if num in d[1]:
        pass
      else:
        bp = 1
        break
    else:
      if num in d[iter[i-1]]:
        pass
      else:
        bp = 1
        break
  if bp == 0:
    cnt += 1

print(cnt)
      