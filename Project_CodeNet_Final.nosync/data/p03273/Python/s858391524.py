H, W = map(int, input().split())
a = [list(input()) for i in range(H)]

#print(a)

while 1:
  h, w = [0, 0]
  hl = []
  for i in range(len(a)):
    w = 0
    for j in range(len(a[0])):
      #print(i, j, a[i][j])
      if a[i][j] != '.':
        w += 1
    #print(w)
        
    if w == 0:
      hl.append(i)
      
  hl.sort(reverse = True)
  for i in hl:
    del a[i]
    
  wl = []
  for i in range(len(a[0])):
    h = 0
    for j in range(len(a)):
      if a[j][i] != '.':
        h += 1
    #print(h)
        
    if h == 0:
      wl.append(i)
      
  wl.sort(reverse = True)
  for i in wl:
    for j in range(len(a)):
      del a[j][i]
        
  if h != 0 and w != 0:
    break
    
for i in range(len(a)):
  print(''.join(a[i]))