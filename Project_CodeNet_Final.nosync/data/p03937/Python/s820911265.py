h,w=map(int,input().split())
s=0
for i in range(h):
  a=input()
  s+=a.count('#')
if s-1==h+w-2:
  print('Possible')
else:
  print('Impossible')