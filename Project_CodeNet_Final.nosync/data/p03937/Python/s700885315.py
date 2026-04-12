h,w=map(int,input().split())
a=[input()for _ in range(h)]
c=0
for i in a:
  for j in i:
    if j=="#":c+=1
if c==h+w-1:print("Possible")
else:print("Impossible")