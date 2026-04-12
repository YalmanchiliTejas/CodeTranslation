h,w=map(int,input().split())
l=[]
for i in range(h):
  l.append(input())
a=[]
for i in range(h):
  if list(set(l[i]))!=list('.'):
    a.append(l[i])
for i in range(w):
  c=True
  for j in range(len(a)):
    if a[j][i]=='#':
      c=False
  if c:
    for j in range(len(a)):
      a[j]=a[j][:i]+'a'+a[j][i+1:]
    w-=1
for i in range(len(a)):
  a[i]=a[i].replace('a','')
for i in range(len(a)):
  print(a[i])