h,w=map(int,input().split())
s=[]
for i in range(h):
  t=input()
  if t.count('.')!=len(t):
    s.append(t)

l=[list(x) for x in zip(*s)]
t2=[]
for e in l:
  if e.count('.')!=len(e):
    t2.append(e)

ans=[list(x) for x in zip(*t2)]
for e in ans:
  print(''.join(e))