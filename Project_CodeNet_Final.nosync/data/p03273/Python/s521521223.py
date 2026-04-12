h, w = map(int, input().split())
lst = []
alldot = [True] * w
for i in range(h):
  s = input()
  if s.count('#') >= 1:
    lst.append(s)
    for t in range(w):
      alldot[t] = alldot[t] and s[t] == '.'
  else:
    h -= 1
res = [''] * h
for i in range(h):
  for j in range(w):
    if alldot[j]:
      pass
    else:
      res[i] += lst[i][j]
for i in res:
  print(i)