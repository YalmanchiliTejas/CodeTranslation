X,Y = map(int,input().split())
whole = []
for i in range(X):
  now = input()
  if now == '.' * Y:
    pass
  else:
    add = []
    for i in range(Y):
      if now[i] == '.':
        add.append(0)
      else:
        add.append(1)
    whole.append(add)
j = 0
while j < len(whole[0]):
  for i in range(len(whole)):
    if whole[i][j] == 1:
      j += 1
      break
  else:
    for i in range(len(whole)):
      del whole[i][j]
for i in range(len(whole)):
  now = whole[i]
  ans = ''
  for j in range(len(now)):
    if now[j] == 0:
      ans += '.'
    else:
      ans += '#'
  print(ans)