h,w=map(int,input().split())
table=[]
for _ in range(h):
  a=input()
  b=[]
  for i in range(w):
    if a[i]=='#':
      b.append(1)
    else:
      b.append(0)
  table.append(b)
ans=0
for i in range(h):
  ans+=sum(table[i])
if ans==h+w-1:
  print('Possible')
else:
  print('Impossible')

 