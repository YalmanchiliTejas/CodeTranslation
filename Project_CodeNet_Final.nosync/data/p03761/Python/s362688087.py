from collections import Counter
n=int(input())
a=[dict(Counter(list(input()))) for i in range(n)]

d=a[0]
for i in a[1:]:
  dl=[]
  for j in d:    
    if j in list(i):
      d[j]=min(d[j],i[j])
    else:
      dl.append(j)
      
  for j in set(dl):  
    del d[j]
    
c=[]
for i in list(d):
  c.append(i*d[i])
c.sort()
m=""
for i in c:
  m=m+i
print(m)