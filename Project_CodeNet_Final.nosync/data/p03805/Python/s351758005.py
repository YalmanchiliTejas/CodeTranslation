n,m = input().split()
n = int(n)
m = int(m)
mat = []
for i in range(n):
  mat.append([])
  for j in range(n):
    mat[-1].append(False)

for i in range(m):
  a,b = input().split()
  mat[int(a)-1][int(b)-1] = True
  mat[int(b)-1][int(a)-1] = True

def count(ar, s):
  if len(ar) == 1:
    return 1 if mat[s][ar[0]] else 0
  num = 0
  for s_next in ar:
    if mat[s][s_next]:
      num += count([x for x in ar if x != s_next], s_next)
  return num

total = 0
for i in range(n):
  ar = [j for j in range(n) if j != i]
  total += count(ar, i)
  break
print(total)

