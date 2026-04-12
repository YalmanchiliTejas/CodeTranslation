h,w = map(int,input().split())
a_list = [input() for nesya in range(h)]

gyo = [False]*h
retsu = [False]*w
for i in range(h):
  for j in range(w):
    if a_list[i][j] == '#':
      gyo[i] = True
      retsu[j] = True
for k in range(h):
  if gyo[k]:
    for l in range(w):
      if retsu[l]:
        print(a_list[k][l], end='')
    print()