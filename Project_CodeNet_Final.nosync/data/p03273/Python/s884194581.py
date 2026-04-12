H,W=[int(s) for s in input().split()]
s=''
for i in range(W):
  s = s + '.' 
ls=[]
for i in range(H):
  x=input()
  if x!=s:
    ls.append(list(x))
i=0
for j in range(W):
  for e in ls:
    if e[i]=='#':
      i+=1
      break
  else:
    for e in ls:
      e.pop(i)
for e in ls:
  print(''.join(e))

    