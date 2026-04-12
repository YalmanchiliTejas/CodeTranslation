h, w = map(int, input().split())

def checkLine(_h,_w):
  flag = True
  for i in range(0,h):
    if a[i][_w] == '#':
      flag = False

  if flag:
    return True

  flag = True
  for i in range(0,w):
    if a[_h][i] == '#':
      flag = False

  if flag:
    return True

  return False

a = []
for i in range(0,h):
  a += input().split()

for i in range(0,h):
  str = ""
  for j in range(0,w):
    if checkLine(i,j) == False:
      str = str + a[i][j]
  if str != "":
    print(str)

