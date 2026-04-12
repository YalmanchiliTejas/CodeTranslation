n=input()
h=list(map(int,input().split()))
m=h[0]
c=0
for i in h:
  if i>=m:
    c+=1
    m=i
  else:pass
print(c)