h,w=map(int,input().split())
a=[]
k=[]
for _ in range(h):
  s=input()
  if '#' in s:
    a.append(s)
l=len(a)
for i in range(w):
  for j in range(l):
    if a[j][i]=='#':
      k.append(i)
      break
m=max(k)
for i in range(l):
  for j in k:
    if j==m:
      print(a[i][j])
    else:
      print(a[i][j],end="")