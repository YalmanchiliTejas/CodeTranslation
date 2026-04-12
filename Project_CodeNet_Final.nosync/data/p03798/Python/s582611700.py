n=int(input())
s=list(input())
s.append(s[0])
f=0
l=['S','S']
for j in range(4):
  for i in range(1,n+1):
    if l[i]=='S':
      if l[i-1]=='S':
        if s[i]=='o':
          l.append('S')
        else:
          l.append('W')
      else:
        if s[i]=='o':
          l.append('W')
        else:
          l.append('S')
    else:
      if l[i-1]=='S':
        if s[i]=='o':
          l.append('W')
        else:
          l.append('S')
      else:
        if s[i]=='o':
          l.append('S')
        else:
          l.append('W')
  if l[n+1]==l[1] and l[n]==l[0]:
    f=1
    break
  else:
    if j==0:
      l=['S','W']
    elif j==1:
      l=['W','S']
    elif j==2:
      l=['W','W']
    else:
      break
if f==0:
  print(-1)
else:
  l.pop()
  l.pop()
  print(''.join(l))