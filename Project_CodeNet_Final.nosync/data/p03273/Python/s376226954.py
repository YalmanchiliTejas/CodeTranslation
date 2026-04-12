n,m=map(int,input().split())
s=[]
for i in range(n):
  t=input()
  if '#' in t:
    s.append(t)
s2=[list(x) for x in zip(*s)]
s3=[]
for i in range(m):
  if '#' in s2[i]:
    s3.append(s2[i])
s4=[list(x) for x in zip(*s3)]
for i in s4:
  print("".join(map(str,i)))
