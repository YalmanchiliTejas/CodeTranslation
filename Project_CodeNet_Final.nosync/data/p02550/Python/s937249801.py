n,x,m=map(int,input().split())
s=set()
ct=x
ans=[x]
s.add(x)
f=0
for i in range(n-1):
  ct**=2
  ct%=m
  if ct not in s:
    s.add(ct)
    ans.append(ct)
  else:
    f=1
    break
if f==0:
  print(sum(ans))
  exit()
y=ans.index(ct)
z=sum(ans[y:len(ans)])
z2=0
for i in range(((n-y)%(len(ans)-y))):
  z2+=ans[y+i]
print(sum(ans[0:y])+z*((n-y)//(len(ans)-y))+z2)