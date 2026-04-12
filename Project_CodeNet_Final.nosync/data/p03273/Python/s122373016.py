H, W = [int(x) for x in input().split()]
a = [x for x in [input() for _ in range(H)] if '#' in x]
w = 0
while w < len(a[0]):
  for h in range(len(a)):
    if a[h][w]=='#':
      w += 1
      break
  else:
    for h in range(len(a)):
      a[h] = a[h][:w] + a[h][w+1:]

for h in range(len(a)):
  print(a[h])