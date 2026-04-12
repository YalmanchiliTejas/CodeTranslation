import itertools

n, m = list(map(int, input().split()))
v = []
for i in range(m):
  tpl = tuple(map(int, input().split()))
  v.append(tpl)
  v.append((tpl[1], tpl[0]))

perms = list(itertools.permutations(range(1, n+1)))
c = 0
for i in perms:
  if i[0] != 1:
    continue
  for j in range(len(i)-1):
    if (i[j], i[j+1]) not in v:
      break
  else:
    c += 1
print(c)
