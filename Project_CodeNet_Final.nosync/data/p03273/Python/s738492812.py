h,w=map(int,input().split())
a=[list(input()) for _ in [0]*h ]
b=[[i[j] for i in a] for j in range(w)]
H,W=[],[]
for i in range(h):
  if a[i]==['.']*w:
    H.append(i)
for j in range(w):
  if b[j]==['.']*h:
    W.append(j)
a=[''.join([a[i][j] if not j in W else '' for j in range(w)]) if not i in H else 0 for i in range(h)]
for i in range(h):
  if type(a[i])!=int:
    print(a[i])