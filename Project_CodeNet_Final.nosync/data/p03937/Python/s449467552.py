h,w=map(int,input().split())
a=[]
c=0
for i in range(h):
  a.append(input())
  c+=a[i].count('#')
flg=0
if c != h+w-1:
  flg=1
dh=0
dw=0
for i in range(h+w-2):
  if dh==h-1:
    if a[dh][dw+1]=='#':
      dw+=1
  elif dw==w-1:
    if a[dh+1][dw]=='#':
      dh+=1
  else:
    if a[dh+1][dw]=='#':
      dh+=1
    elif a[dh][dw+1]=='#':
      dw+=1
    else:
      flg=1
if flg==0:
  print('Possible')
else:
  print('Impossible')