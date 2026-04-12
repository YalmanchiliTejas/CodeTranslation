n,m=map(int,input().split())
L=[]
d=set(".")
for i in range(n):
  s=input()
  if set(list(s))!=d:
    L.append(list(s))
l=[list(a) for a in  zip(*L) if set(a)!=set(".")]
for a in zip(*l):
  print("".join(a))