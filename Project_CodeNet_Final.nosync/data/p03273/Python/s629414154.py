H,W=map(int,input().split())
m=[]
for _ in[0]*H:
  l=input()
  if l!='.'*W:m+=[l]
t=[]
for j in range(W):
  f=0
  for l in m:
    if l[j]!='.':f=1;break
  if f:t+=[j]
for l in m:
  print("".join([l[j] for j in t])) 