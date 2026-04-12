h,w=map(int,input().split())
a=[]
b=[]
f=0
for i in range(h):
  b=input()
  if b!='.'*w:
    a.append(b)
ans=['' for j in range(len(a))]
for i in range(len(a[0])):
  f=0
  for j in range(len(a)):
    if a[j][i]=='#':
      f=1
      break
  if f==1:
    for k in range(len(a)):
      ans[k]+=a[k][i]
for i in range(len(a)):
  print(ans[i])