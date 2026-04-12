H,W = map(int,input().split())

a=[]
for _ in range(H):
  w = input()
  if w != '.'*W:
    a.append(w)
  else:
    continue

b=[]
for i in range(W):
  c = ""
  for j in range(len(a)):
    c += a[j][i]
  if c != '.'*len(a):
    b.append(c)
  else:
    continue

d=[]
for i in range(len(b[0])):
  e = ""
  for j in range(len(b)):
    e += b[j][i]
  d.append(e)

print('\n'.join(d))  
    