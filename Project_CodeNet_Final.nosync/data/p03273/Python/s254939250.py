h, w = map(int, input().split())
a = []



for i in range(h):
  l = input()
  if '#' in l:
    a.append(l)
    
z = [False] * w

for i in range(w):
  for l in a:
    if l[i] == '#':
      z[i] = True
      break
    


for j, _ in enumerate(a):
  for i in range(w) :
    if z[i]:
      print(_[i], end='')
  if j == len(a) -1:
    break
  print('')