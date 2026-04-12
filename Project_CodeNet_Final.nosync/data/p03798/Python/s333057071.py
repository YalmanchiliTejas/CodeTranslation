n =int(input())
s = input()
cir = ['']*n
judge = ''
def convertSW(x):
  if x == 'S':
    return 'W'
  elif x == 'W':
    return 'S'
for i in range(4):
  if i == 0:
    cir[0],cir[1] = 'S','S'
  elif i == 1:
    cir[0],cir[1] = 'S','W'
  elif i == 2:
    cir[0],cir[1] = 'W','W'
  else:
    cir[0],cir[1] = 'W','S'
  if (s[0] == 'o' and cir[0] == 'S') or (s[0] == 'x' and cir[0] == 'W'):
    judge = cir[1]
  else:
    judge = convertSW(cir[1])
  for j in range(2,n):
    if (s[j-1] == 'o' and cir[j-1] == 'S') or (s[j-1] == 'x' and cir[j-1] == 'W'):
      cir[j] = cir[j-2]
    else:
      cir[j] = convertSW(cir[j-2])
  if (s[-1] == 'o' and cir[-1] == 'S') or (s[-1] == 'x' and cir[-1] == 'W'):
    if (cir[0] == cir[-2]) and (judge == cir[-1]):
      print(''.join(cir))
      exit()
  else:
    if cir[0] == convertSW(cir[-2]) and (judge == cir[-1]):
      print(''.join(cir))
      exit()
print(-1)