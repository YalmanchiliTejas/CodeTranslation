h,w = map(int,input().split())

a = [0]*h
b = []
for i in range(0,h):
  a[i] = input()
  
i = 0
tmp = 0
for i in range(0,h):
  if a[i].count(".") == w:
    tmp += 1
  else:
    b.append(a[i])
    
#print(b) 

b = list(zip(*b))
#print(b)
c = []
h = h - tmp
#print(h)
tmp = []

for i in range(0,w):
  if b[i].count(".") == h:
    continue
  else:
    c.append(b[i])
    
#print(c)

c = list(zip(*c))

for i in c:
  i = ''.join(i)
  print(i)
