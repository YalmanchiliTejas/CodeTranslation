h,w = map(int,input().split())
H = []
l = []
for i in range(h):
  k = list(input())
  if len(set(k)) == 1 and k[0] == '.':
    H.append(i)
  l.append(k)
W = []
for j in range(w):
  flag = True
  x = l[0][j]
  if x == '.':
    for k in l:
      if k[j] != x:
        flag = False
    if flag:
      W.append(j)
for i in H: 
  for j in range(w):
    l[i][j] = ''
for j in W:
  for i in range(h):
    l[i][j] = ''
for k in l:
  if ''.join(k) != '':
    print(''.join(k))