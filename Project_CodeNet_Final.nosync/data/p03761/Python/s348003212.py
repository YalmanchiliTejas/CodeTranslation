n=int(input())
d=dict()
for i in input():
  if i not in d:
    d[i]=1
  else:
    d[i]+=1
for _ in range(n-1):
  dd=dict()
  for i in input():
    if i not in dd:
      dd[i]=1
    else:
      dd[i]+=1
  for i in d.keys():
    if i in dd:
      d[i]=min(d[i],dd[i])
    else:
      d[i]=0
ans=[]
for i in d.keys():
  for _ in range(d[i]):
    ans.append(i)
ans.sort()
a=""
for i in ans:
  a+=i
print(a)
