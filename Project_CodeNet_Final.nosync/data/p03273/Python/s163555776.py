#abc107b

h,w=map(int,input().split())
a=[]
for i in range(h):
 t=input()
 if t=='.'*w:
  continue
 a.append(list(t))
b=list(map(list, zip(*a)))
c=[]
for i in range(len(b)):
 if all(x=='.' for x in b[i]):
  continue
 c.append(b[i])
l=list(map(list, zip(*c)))
for i in range(len(l)):
 print(''.join(l[i]))
