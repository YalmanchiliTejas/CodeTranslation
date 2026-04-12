h, w = map(int, input().split())
l = []
for i in range(h):
  a = str(input())
  if a == '.'*w:
    continue
  l.append(a)

skip = []
for i in range(w):
  for j in range(len(l)):
    if l[j][i] == '#':
      break
  else:
    skip.append(i)

skip = set(skip)
l_ = [0]*len(l)
for i in range(len(l)):
  temp = ''
  for j in range(w):
    if j not in skip:
      temp += l[i][j]
  l_[i] = temp
  
for i in range(len(l_)):
  print(l_[i])