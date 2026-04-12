h,w=map(int,input().split())
a=[]
for i in range(h):
  aa=list(input())
  if "#" not in aa:
    continue
  else:
    a.append(aa)
aa=[]
for i in range(w):
  c=0
  for j in range(len(a)):
    if a[j][i]=="#":
      c+=1
  if c==0:
    aa.append(i)
aa.reverse()
for i in aa:
  for j in range(len(a)):
    del a[j][i]
for i in range(len(a)):
  print("".join(a[i]))
