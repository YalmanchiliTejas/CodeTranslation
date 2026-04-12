h,w=map(int,input().split())
norow=set()
nocolumn=set()
s=[]
for i in range(h):
  a=input()
  s.append(a)
for i in range(h):
  flag=0
  for j in range(w):
    if s[i][j]=='#':
      flag=1
  if flag==0:
    norow.add(i)
for j in range(w):
  flag=0
  for i in range(h):
    if s[i][j]=='#':
      flag=1
  if flag==0:
    nocolumn.add(j)
for i in range(h):
  if i in norow:
    continue
  ans=[]
  for j in range(w):
    if j in nocolumn:
      continue
    ans.append(s[i][j])
  print(''.join(ans))