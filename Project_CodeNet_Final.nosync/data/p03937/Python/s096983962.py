h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
c=0
for j in range(h):
  for k in range(w):
    if a[j][k]=='#':c+=1
if c==h+w-1:print('Possible')
else:print('Impossible')