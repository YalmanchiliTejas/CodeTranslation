h,w=map(int,input().split())
a=[[j for j in input()] for i in range(h)]
for i in range(h):
  if a[i].count('.')==w:
    a[i]=[]
while [] in a:
  a.remove([])
for i in range(w):
  c=0
  for j in range(len(a)):
    if a[j][i]=='.':
      c+=1
  if c==len(a):
    for j in range(len(a)):
      a[j][i]='!'
for i in range(len(a)):
  while '!' in a[i]:
    a[i].remove('!')
for i in a:
  print(*i,sep='')