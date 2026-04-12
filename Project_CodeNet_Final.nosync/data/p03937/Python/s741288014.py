h,w=map(int,input().split())
a=[]
for i in range(h):
  x=input()
  a.append(x)
cnt=0
for i in range(h):
  cnt+=a[i].count('#')
if cnt==h+w-1:
  print('Possible')
else:
  print('Impossible')