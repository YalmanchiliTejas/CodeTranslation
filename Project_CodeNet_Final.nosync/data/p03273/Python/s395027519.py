h, w = map(int, input().split())
a = []

for i in range(h):
  j = list(input())
  if '#' in j:
    a.append(j)
    
ans = zip(*[i for i in zip(*a) if '#' in i])

for t in ans:
  print(''.join(t))