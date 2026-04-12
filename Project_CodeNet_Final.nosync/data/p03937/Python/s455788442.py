h,w=map(int,input().split())
a=[list(input()+'.') for _ in range(h)]
d=['.']*(w+1)
a.append(d)
x=1
i=0;j=0
a[0][0]='.'
while i!=h-1 or j!=w-1:
  if a[i+1][j]=='#':
    if a[i][j+1]=='#':
      x=0
      break
    else:
      i=i+1
      a[i][j]='.'
  else:
    if a[i][j+1]=='.':
      x=0
      break
    else:
      j=j+1
      a[i][j]='.'
if x==1:
  for k in range(h):
    if '#' in a[k]:
      x=0
      break
print('Possible' if x==1 else 'Impossible')