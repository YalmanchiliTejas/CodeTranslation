_,*l=map(int,open(0).read().split())
m=c=0
for i in l:
  if m<=i: m=i; c+=1
print(c)