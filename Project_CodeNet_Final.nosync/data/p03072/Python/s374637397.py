input()
r=list(map(int,input().split()))

c=0
m=0
for i in r:
  m=max(m,i)
  if m==i:c+=1
print(c)