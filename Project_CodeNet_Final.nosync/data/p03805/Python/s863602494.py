import itertools

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(m)]

c = [i for i in range(2, n + 1)]
b = []
for x in itertools.permutations(c):
  b.append([1] + list(x))
  
cnt = 0
for x in b:
  exist = True
  for i in range(n-1):
    if not sorted(x[i:i+2]) in a:
      exist = False
      break
  if exist:
    cnt += 1

print(cnt)