h,w=map(int,input().split())
a=[[c for c in input()] for _ in range(h)]
b=[]
flag=0
for s in a:
  if "#" in s:
    b.append(s)
for i in range(w):
  flag=0
  for j in range(len(b)):
    if b[j][i]=="#":
      flag=1
      break
  if flag==0:
    for j in range(len(b)):
      b[j][i]=""
for s in b:
  print("".join(s))