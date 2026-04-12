h, w = [int(x) for x in input().split()]
masu = [input() for i in range(h)]
for i in range(h):
  for j in range(w):
    if all([masu[i][k] == '.' for k in range(w)]):
      break
    elif all([masu[k][j] == '.' for k in range(h)]):
      continue
    else:
      print(masu[i][j], sep='', end='')
  else:
    print('')
  