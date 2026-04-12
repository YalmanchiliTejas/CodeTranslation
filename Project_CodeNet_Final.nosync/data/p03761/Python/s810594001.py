from collections import defaultdict
n=int(input())
d={}
w=list(input())
d1=defaultdict(int)
num=len(w)
for i in range(num):
  d1[w[i]]+=1
for i in d1:
  d[i]=d1[i]
for i in range(n-1):
  w=list(input())
  d1=defaultdict(int)
  num=len(w)
  for i in range(num):
    d1[w[i]]+=1
  for j in d:
    if d[j]>d1[j]:
      d[j]=d1[j]
l=[]
for i in d:
  l.append(d[i]*i)
if l==[]:
  print("")
else:
  l=sorted(l)
  ans=""
  for i in l:
    ans+=i
  print(ans)