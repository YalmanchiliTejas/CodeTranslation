h,w=map(int,input().split())
a=[input()for _ in range(h)]
b=[]
v=list(map(int,'0'*w))
for i,r in enumerate(a):
  if r=='.'*w:
    b.append(i)
  for j in range(w):
    v[j]+=r[j]=='.'
f=[j for j in range(w)if v[j]==h]
for i,r in enumerate(a):
  if i not in b:
    t=list(map(str,a[i]))
    for j in f:
      t[j]=''
    print(''.join(t))
