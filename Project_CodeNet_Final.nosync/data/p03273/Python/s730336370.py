h,w=map(int,input().split());b=[input()for i in range(h)];a=[]
for i in b:
  if i!="."*w:a.insert(0,i)
b=[]
for i in range(w):
  s=""
  for j in a:s=j[i]+s
  if s!="."*len(a):b.insert(0,s)
c=[]
for i in range(len(a)):
  s=""
  for j in b:
    s=j[i]+s
  print(s)