n=int(input());s=[]
def listpu(s):
  ans=[]
  for i in s:
    if not i in ans:ans.append(i)
  return sorted(ans)
def listsa(a,b):
  x=[]
  for i in a:
    if i in b:x.append(i)
  return sorted(x)
for i in range(n):
  s.append(input())
  if i==0:b=listpu(s[0])
  else:b=listsa(b,listpu(s[i]))
a=[100]*len(b)
for i in range(len(b)):
  for j in s:
    c=0
    for h in j:
      if h==b[i]:c+=1
    a[i]=min(a[i],c)
ans=""
for i in range(len(a)):ans+=b[i]*a[i]
print(ans)